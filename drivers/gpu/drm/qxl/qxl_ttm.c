/*
 * Copyright 2013 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Dave Airlie
 *          Alon Levy
 */

#include <linux/delay.h>

#include <drm/drm.h>
#include <drm/drm_file.h>
#include <drm/drm_debugfs.h>
#include <drm/qxl_drm.h>
#include <drm/ttm/ttm_bo_api.h>
#include <drm/ttm/ttm_bo_driver.h>
#include <drm/ttm/ttm_module.h>
#include <drm/ttm/ttm_page_alloc.h>
#include <drm/ttm/ttm_placement.h>

#include "qxl_drv.h"
#include "qxl_object.h"

static struct qxl_device *qxl_get_qdev(struct ttm_bo_device *bdev)
{
	struct qxl_mman *mman;
	struct qxl_device *qdev;

	mman = container_of(bdev, struct qxl_mman, bdev);
	qdev = container_of(mman, struct qxl_device, mman);
	return qdev;
}

static void qxl_evict_flags(struct ttm_buffer_object *bo,
				struct ttm_placement *placement)
{
	struct qxl_bo *qbo;
	static const struct ttm_place placements = {
		.fpfn = 0,
		.lpfn = 0,
		.flags = TTM_PL_MASK_CACHING | TTM_PL_FLAG_SYSTEM
	};

	if (!qxl_ttm_bo_is_qxl_bo(bo)) {
		placement->placement = &placements;
		placement->busy_placement = &placements;
		placement->num_placement = 1;
		placement->num_busy_placement = 1;
		return;
	}
	qbo = to_qxl_bo(bo);
	qxl_ttm_placement_from_domain(qbo, QXL_GEM_DOMAIN_CPU, false);
	*placement = qbo->placement;
}

int qxl_ttm_io_mem_reserve(struct ttm_bo_device *bdev,
			   struct ttm_resource *mem)
{
	struct qxl_device *qdev = qxl_get_qdev(bdev);

	switch (mem->mem_type) {
	case TTM_PL_SYSTEM:
		/* system memory */
		return 0;
	case TTM_PL_VRAM:
		mem->bus.is_iomem = true;
		mem->bus.base = qdev->vram_base;
		mem->bus.offset = mem->start << PAGE_SHIFT;
		break;
	case TTM_PL_PRIV:
		mem->bus.is_iomem = true;
		mem->bus.base = qdev->surfaceram_base;
		mem->bus.offset = mem->start << PAGE_SHIFT;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

/*
 * TTM backend functions.
 */
struct qxl_ttm_tt {
	struct ttm_tt		        ttm;
	struct qxl_device		*qdev;
	u64				offset;
};

static int qxl_ttm_backend_bind(struct ttm_tt *ttm,
				struct ttm_resource *bo_mem)
{
	struct qxl_ttm_tt *gtt = (void *)ttm;

	gtt->offset = (unsigned long)(bo_mem->start << PAGE_SHIFT);
	if (!ttm->num_pages) {
		WARN(1, "nothing to bind %lu pages for mreg %p back %p!\n",
		     ttm->num_pages, bo_mem, ttm);
	}
	/* Not implemented */
	return -1;
}

static void qxl_ttm_backend_unbind(struct ttm_tt *ttm)
{
	/* Not implemented */
}

static void qxl_ttm_backend_destroy(struct ttm_tt *ttm)
{
	struct qxl_ttm_tt *gtt = (void *)ttm;

	ttm_tt_fini(&gtt->ttm);
	kfree(gtt);
}

static struct ttm_backend_func qxl_backend_func = {
	.bind = &qxl_ttm_backend_bind,
	.unbind = &qxl_ttm_backend_unbind,
	.destroy = &qxl_ttm_backend_destroy,
};

static struct ttm_tt *qxl_ttm_tt_create(struct ttm_buffer_object *bo,
					uint32_t page_flags)
{
	struct qxl_device *qdev;
	struct qxl_ttm_tt *gtt;

	qdev = qxl_get_qdev(bo->bdev);
	gtt = kzalloc(sizeof(struct qxl_ttm_tt), GFP_KERNEL);
	if (gtt == NULL)
		return NULL;
	gtt->ttm.func = &qxl_backend_func;
	gtt->qdev = qdev;
	if (ttm_tt_init(&gtt->ttm, bo, page_flags)) {
		kfree(gtt);
		return NULL;
	}
	return &gtt->ttm;
}

static void qxl_move_null(struct ttm_buffer_object *bo,
			     struct ttm_resource *new_mem)
{
	struct ttm_resource *old_mem = &bo->mem;

	BUG_ON(old_mem->mm_node != NULL);
	*old_mem = *new_mem;
	new_mem->mm_node = NULL;
}

static int qxl_bo_move(struct ttm_buffer_object *bo, bool evict,
		       struct ttm_operation_ctx *ctx,
		       struct ttm_resource *new_mem)
{
	struct ttm_resource *old_mem = &bo->mem;
	int ret;

	ret = ttm_bo_wait(bo, ctx->interruptible, ctx->no_wait_gpu);
	if (ret)
		return ret;

	if (old_mem->mem_type == TTM_PL_SYSTEM && bo->ttm == NULL) {
		qxl_move_null(bo, new_mem);
		return 0;
	}
	return ttm_bo_move_memcpy(bo, ctx, new_mem);
}

static void qxl_bo_move_notify(struct ttm_buffer_object *bo,
			       bool evict,
			       struct ttm_resource *new_mem)
{
	struct qxl_bo *qbo;
	struct qxl_device *qdev;

	if (!qxl_ttm_bo_is_qxl_bo(bo))
		return;
	qbo = to_qxl_bo(bo);
	qdev = to_qxl(qbo->tbo.base.dev);

	if (bo->mem.mem_type == TTM_PL_PRIV && qbo->surface_id)
		qxl_surface_evict(qdev, qbo, new_mem ? true : false);
}

static struct ttm_bo_driver qxl_bo_driver = {
	.ttm_tt_create = &qxl_ttm_tt_create,
	.eviction_valuable = ttm_bo_eviction_valuable,
	.evict_flags = &qxl_evict_flags,
	.move = &qxl_bo_move,
	.io_mem_reserve = &qxl_ttm_io_mem_reserve,
	.move_notify = &qxl_bo_move_notify,
};

static int qxl_ttm_init_mem_type(struct qxl_device *qdev,
				 unsigned int type,
				 uint64_t size)
{
	return ttm_range_man_init(&qdev->mman.bdev, type, TTM_PL_MASK_CACHING,
				  TTM_PL_FLAG_CACHED, false, size);
}

int qxl_ttm_init(struct qxl_device *qdev)
{
	int r;
	int num_io_pages; /* != rom->num_io_pages, we include surface0 */

	/* No others user of address space so set it to 0 */
	r = ttm_bo_device_init(&qdev->mman.bdev,
			       &qxl_bo_driver,
			       qdev->ddev.anon_inode->i_mapping,
			       qdev->ddev.vma_offset_manager,
			       false);
	if (r) {
		DRM_ERROR("failed initializing buffer object driver(%d).\n", r);
		return r;
	}
	/* NOTE: this includes the framebuffer (aka surface 0) */
	num_io_pages = qdev->rom->ram_header_offset / PAGE_SIZE;
	r = qxl_ttm_init_mem_type(qdev, TTM_PL_VRAM, num_io_pages);
	if (r) {
		DRM_ERROR("Failed initializing VRAM heap.\n");
		return r;
	}
	r = qxl_ttm_init_mem_type(qdev, TTM_PL_PRIV,
				  qdev->surfaceram_size / PAGE_SIZE);
	if (r) {
		DRM_ERROR("Failed initializing Surfaces heap.\n");
		return r;
	}
	DRM_INFO("qxl: %uM of VRAM memory size\n",
		 (unsigned int)qdev->vram_size / (1024 * 1024));
	DRM_INFO("qxl: %luM of IO pages memory ready (VRAM domain)\n",
		 ((unsigned int)num_io_pages * PAGE_SIZE) / (1024 * 1024));
	DRM_INFO("qxl: %uM of Surface memory size\n",
		 (unsigned int)qdev->surfaceram_size / (1024 * 1024));
	return 0;
}

void qxl_ttm_fini(struct qxl_device *qdev)
{
	ttm_range_man_fini(&qdev->mman.bdev, TTM_PL_VRAM);
	ttm_range_man_fini(&qdev->mman.bdev, TTM_PL_PRIV);
	ttm_bo_device_release(&qdev->mman.bdev);
	DRM_INFO("qxl: ttm finalized\n");
}

#define QXL_DEBUGFS_MEM_TYPES 2

#if defined(CONFIG_DEBUG_FS)
static int qxl_mm_dump_table(struct seq_file *m, void *data)
{
	struct drm_info_node *node = (struct drm_info_node *)m->private;
	struct ttm_resource_manager *man = (struct ttm_resource_manager *)node->info_ent->data;
	struct drm_printer p = drm_seq_file_printer(m);

	ttm_resource_manager_debug(man, &p);
	return 0;
}
#endif

void qxl_ttm_debugfs_init(struct qxl_device *qdev)
{
#if defined(CONFIG_DEBUG_FS)
	static struct drm_info_list qxl_mem_types_list[QXL_DEBUGFS_MEM_TYPES];
	static char qxl_mem_types_names[QXL_DEBUGFS_MEM_TYPES][32];
	unsigned int i;

	for (i = 0; i < QXL_DEBUGFS_MEM_TYPES; i++) {
		if (i == 0)
			sprintf(qxl_mem_types_names[i], "qxl_mem_mm");
		else
			sprintf(qxl_mem_types_names[i], "qxl_surf_mm");
		qxl_mem_types_list[i].name = qxl_mem_types_names[i];
		qxl_mem_types_list[i].show = &qxl_mm_dump_table;
		qxl_mem_types_list[i].driver_features = 0;
		if (i == 0)
			qxl_mem_types_list[i].data = ttm_manager_type(&qdev->mman.bdev, TTM_PL_VRAM);
		else
			qxl_mem_types_list[i].data = ttm_manager_type(&qdev->mman.bdev, TTM_PL_PRIV);

	}
	qxl_debugfs_add_files(qdev, qxl_mem_types_list, i);
#endif
}
