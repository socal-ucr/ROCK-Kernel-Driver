# SPDX-License-Identifier: MIT
amdkcl-y += main.o symbols.o kcl_common.o

amdkcl-y += dma-buf/dma-resv.o

amdkcl-y += kcl_backlight.o kcl_ioctl.o \
	kcl_kthread.o kcl_io.o kcl_perf_event.o kcl_seq_file.o \
	kcl_suspend.o kcl_pci.o kcl_mm.o kcl_memory.o kcl_sched.o \
	kcl_fence.o kcl_fence_array.o kcl_reservation.o kcl_drm_cache.o \
	kcl_drm_auth.o kcl_drm_fb.o kcl_fbmem.o kcl_drm_print.o \
	kcl_drm_crtc.o kcl_drm_connector.o kcl_drm_atomic_helper.o \
	kcl_device_cgroup.o kcl_mn.o kcl_drm_modes.o kcl_time.o kcl_ftrace.o \
	kcl_acpi_table.o

amdkcl-$(CONFIG_MMU_NOTIFIER) += kcl_mn.o
amdkcl-$(CONFIG_DRM_AMD_DC_HDCP) += kcl_drm_hdcp.o

# for trace-points
CFLAGS_kcl_fence.o := -I$(src)

ccflags-y += \
	-include $(src)/../dkms/config/config.h \
	-include $(src)/kcl_common.h

ccflags-y += -DHAVE_CONFIG_H

obj-m += amdkcl.o
