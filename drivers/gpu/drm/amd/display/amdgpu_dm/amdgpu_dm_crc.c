/*
 * Copyright 2015 Advanced Micro Devices, Inc.
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
 * Authors: AMD
 *
 */

#include <drm/drm_crtc.h>
#include <drm/drm_vblank.h>

#include "amdgpu.h"
#include "amdgpu_dm.h"
#include "dc.h"

#ifdef HAVE_STRUCT_DRM_CRTC_FUNCS_GET_VERIFY_CRC_SOURCES
static const char *const pipe_crc_sources[] = {
	"none",
	"crtc",
	"crtc dither",
	"dprx",
	"dprx dither",
	"auto",
};
#endif

static enum amdgpu_dm_pipe_crc_source dm_parse_crc_source(const char *source)
{
	if (!source || !strcmp(source, "none"))
		return AMDGPU_DM_PIPE_CRC_SOURCE_NONE;
	if (!strcmp(source, "auto") || !strcmp(source, "crtc"))
		return AMDGPU_DM_PIPE_CRC_SOURCE_CRTC;
	if (!strcmp(source, "dprx"))
		return AMDGPU_DM_PIPE_CRC_SOURCE_DPRX;
	if (!strcmp(source, "crtc dither"))
		return AMDGPU_DM_PIPE_CRC_SOURCE_CRTC_DITHER;
	if (!strcmp(source, "dprx dither"))
		return AMDGPU_DM_PIPE_CRC_SOURCE_DPRX_DITHER;

	return AMDGPU_DM_PIPE_CRC_SOURCE_INVALID;
}

static bool dm_is_crc_source_crtc(enum amdgpu_dm_pipe_crc_source src)
{
	return (src == AMDGPU_DM_PIPE_CRC_SOURCE_CRTC) ||
	       (src == AMDGPU_DM_PIPE_CRC_SOURCE_CRTC_DITHER);
}

static bool dm_is_crc_source_dprx(enum amdgpu_dm_pipe_crc_source src)
{
	return (src == AMDGPU_DM_PIPE_CRC_SOURCE_DPRX) ||
	       (src == AMDGPU_DM_PIPE_CRC_SOURCE_DPRX_DITHER);
}

static bool dm_need_crc_dither(enum amdgpu_dm_pipe_crc_source src)
{
	return (src == AMDGPU_DM_PIPE_CRC_SOURCE_CRTC_DITHER) ||
	       (src == AMDGPU_DM_PIPE_CRC_SOURCE_DPRX_DITHER) ||
	       (src == AMDGPU_DM_PIPE_CRC_SOURCE_NONE);
}

#ifdef HAVE_STRUCT_DRM_CRTC_FUNCS_GET_VERIFY_CRC_SOURCES
const char *const *amdgpu_dm_crtc_get_crc_sources(struct drm_crtc *crtc,
						  size_t *count)
{
	*count = ARRAY_SIZE(pipe_crc_sources);
	return pipe_crc_sources;
}

int
amdgpu_dm_crtc_verify_crc_source(struct drm_crtc *crtc, const char *src_name,
				 size_t *values_cnt)
{
	enum amdgpu_dm_pipe_crc_source source = dm_parse_crc_source(src_name);

	if (source < 0) {
		DRM_DEBUG_DRIVER("Unknown CRC source %s for CRTC%d\n",
				 src_name, crtc->index);
		return -EINVAL;
	}

	*values_cnt = 3;
	return 0;
}
#endif

static void amdgpu_dm_set_crc_window_default(struct dm_crtc_state *dm_crtc_state)
{
	dm_crtc_state->crc_window.x_start = 0;
	dm_crtc_state->crc_window.y_start = 0;
	dm_crtc_state->crc_window.x_end = 0;
	dm_crtc_state->crc_window.y_end = 0;
}

bool amdgpu_dm_crc_window_is_default(struct dm_crtc_state *dm_crtc_state)
{
	bool ret = true;

	if ((dm_crtc_state->crc_window.x_start != 0) ||
		(dm_crtc_state->crc_window.y_start != 0) ||
		(dm_crtc_state->crc_window.x_end != 0) ||
		(dm_crtc_state->crc_window.y_end != 0))
		ret = false;

	return ret;
}

bool amdgpu_dm_crc_window_changed(struct dm_crtc_state *dm_new_crtc_state,
					struct dm_crtc_state *dm_old_crtc_state)
{
	bool ret = false;

	if ((dm_new_crtc_state->crc_window.x_start != dm_old_crtc_state->crc_window.x_start) ||
		(dm_new_crtc_state->crc_window.y_start != dm_old_crtc_state->crc_window.y_start) ||
		(dm_new_crtc_state->crc_window.x_end != dm_old_crtc_state->crc_window.x_end) ||
		(dm_new_crtc_state->crc_window.y_end != dm_old_crtc_state->crc_window.y_end))
		ret = true;

	return ret;
}

#ifdef HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CRC_SOURCE
int amdgpu_dm_crtc_configure_crc_source(struct drm_crtc *crtc,
					struct dm_crtc_state *dm_crtc_state,
					enum amdgpu_dm_pipe_crc_source source)
{
	struct amdgpu_device *adev = drm_to_adev(crtc->dev);
	struct dc_stream_state *stream_state = dm_crtc_state->stream;
	bool enable = amdgpu_dm_is_valid_crc_source(source);
	int ret = 0;
	struct crc_params *crc_window = NULL, tmp_window;

	/* Configuration will be deferred to stream enable. */
	if (!stream_state)
		return 0;

	mutex_lock(&adev->dm.dc_lock);

	/* Enable CRTC CRC generation if necessary. */
	if (dm_is_crc_source_crtc(source) || source == AMDGPU_DM_PIPE_CRC_SOURCE_NONE) {
		if (!enable)
			amdgpu_dm_set_crc_window_default(dm_crtc_state);

		if (!amdgpu_dm_crc_window_is_default(dm_crtc_state)) {
			crc_window = &tmp_window;

			tmp_window.windowa_x_start = dm_crtc_state->crc_window.x_start;
			tmp_window.windowa_y_start = dm_crtc_state->crc_window.y_start;
			tmp_window.windowa_x_end = dm_crtc_state->crc_window.x_end;
			tmp_window.windowa_y_end = dm_crtc_state->crc_window.y_end;
			tmp_window.windowb_x_start = dm_crtc_state->crc_window.x_start;
			tmp_window.windowb_y_start = dm_crtc_state->crc_window.y_start;
			tmp_window.windowb_x_end = dm_crtc_state->crc_window.x_end;
			tmp_window.windowb_y_end = dm_crtc_state->crc_window.y_end;
		}

		if (!dc_stream_configure_crc(stream_state->ctx->dc,
					     stream_state, crc_window, enable, enable)) {
			ret = -EINVAL;
			goto unlock;
		}
	}

	/* Configure dithering */
	if (!dm_need_crc_dither(source)) {
		dc_stream_set_dither_option(stream_state, DITHER_OPTION_TRUN8);
		dc_stream_set_dyn_expansion(stream_state->ctx->dc, stream_state,
					    DYN_EXPANSION_DISABLE);
	} else {
		dc_stream_set_dither_option(stream_state,
					    DITHER_OPTION_DEFAULT);
		dc_stream_set_dyn_expansion(stream_state->ctx->dc, stream_state,
					    DYN_EXPANSION_AUTO);
	}

unlock:
	mutex_unlock(&adev->dm.dc_lock);

	return ret;
}

#if defined(HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CRC_SOURCE_2ARGS)
int amdgpu_dm_crtc_set_crc_source(struct drm_crtc *crtc, const char *src_name)
#else
int amdgpu_dm_crtc_set_crc_source(struct drm_crtc *crtc, const char *src_name,
				  size_t *values_cnt)
#endif
{
	enum amdgpu_dm_pipe_crc_source source = dm_parse_crc_source(src_name);
	struct drm_crtc_commit *commit;
	struct dm_crtc_state *crtc_state;
	struct drm_dp_aux *aux = NULL;
	bool enable = false;
	bool enabled = false;
	int ret = 0;

	if (source < 0) {
		DRM_DEBUG_DRIVER("Unknown CRC source %s for CRTC%d\n",
				 src_name, crtc->index);
		return -EINVAL;
	}

	ret = drm_modeset_lock(&crtc->mutex, NULL);
	if (ret)
		return ret;

	spin_lock(&crtc->commit_lock);
	commit = list_first_entry_or_null(&crtc->commit_list,
					  struct drm_crtc_commit, commit_entry);
	if (commit)
		drm_crtc_commit_get(commit);
	spin_unlock(&crtc->commit_lock);

	if (commit) {
		/*
		 * Need to wait for all outstanding programming to complete
		 * in commit tail since it can modify CRC related fields and
		 * hardware state. Since we're holding the CRTC lock we're
		 * guaranteed that no other commit work can be queued off
		 * before we modify the state below.
		 */
		ret = wait_for_completion_interruptible_timeout(
			&commit->hw_done, 10 * HZ);
		if (ret)
			goto cleanup;
	}

	enable = amdgpu_dm_is_valid_crc_source(source);
	crtc_state = to_dm_crtc_state(crtc->state);

	/*
	 * USER REQ SRC | CURRENT SRC | BEHAVIOR
	 * -----------------------------
	 * None         | None        | Do nothing
	 * None         | CRTC        | Disable CRTC CRC, set default to dither
	 * None         | DPRX        | Disable DPRX CRC, need 'aux', set default to dither
	 * None         | CRTC DITHER | Disable CRTC CRC
	 * None         | DPRX DITHER | Disable DPRX CRC, need 'aux'
	 * CRTC         | XXXX        | Enable CRTC CRC, no dither
	 * DPRX         | XXXX        | Enable DPRX CRC, need 'aux', no dither
	 * CRTC DITHER  | XXXX        | Enable CRTC CRC, set dither
	 * DPRX DITHER  | XXXX        | Enable DPRX CRC, need 'aux', set dither
	 */
	if (dm_is_crc_source_dprx(source) ||
	    (source == AMDGPU_DM_PIPE_CRC_SOURCE_NONE &&
	     dm_is_crc_source_dprx(crtc_state->crc_src))) {
		struct amdgpu_dm_connector *aconn = NULL;
		struct drm_connector *connector;
#ifdef HAVE_DRM_CONNECTOR_LIST_ITER_BEGIN
		struct drm_connector_list_iter conn_iter;
#endif

#ifdef HAVE_DRM_CONNECTOR_LIST_ITER_BEGIN
		drm_connector_list_iter_begin(crtc->dev, &conn_iter);
		drm_for_each_connector_iter(connector, &conn_iter) {
#else
		list_for_each_entry(connector, &(crtc->dev)->mode_config.connector_list, head) {
#endif
			if (!connector->state || connector->state->crtc != crtc)
				continue;

			aconn = to_amdgpu_dm_connector(connector);
			break;
		}
#ifdef HAVE_DRM_CONNECTOR_LIST_ITER_BEGIN
		drm_connector_list_iter_end(&conn_iter);
#endif

		if (!aconn) {
			DRM_DEBUG_DRIVER("No amd connector matching CRTC-%d\n", crtc->index);
			ret = -EINVAL;
			goto cleanup;
		}

		aux = &aconn->dm_dp_aux.aux;

		if (!aux) {
			DRM_DEBUG_DRIVER("No dp aux for amd connector\n");
			ret = -EINVAL;
			goto cleanup;
		}
	}

	if (amdgpu_dm_crtc_configure_crc_source(crtc, crtc_state, source)) {
		ret = -EINVAL;
		goto cleanup;
	}

	/*
	 * Reading the CRC requires the vblank interrupt handler to be
	 * enabled. Keep a reference until CRC capture stops.
	 */
	enabled = amdgpu_dm_is_valid_crc_source(crtc_state->crc_src);
	if (!enabled && enable) {
		ret = drm_crtc_vblank_get(crtc);
		if (ret)
			goto cleanup;

		if (dm_is_crc_source_dprx(source)) {
#ifdef HAVE_DRM_DP_START_CRC
			if (drm_dp_start_crc(aux, crtc)) {
				DRM_DEBUG_DRIVER("dp start crc failed\n");
				ret = -EINVAL;
				goto cleanup;
			}
#endif
		}
	} else if (enabled && !enable) {
		drm_crtc_vblank_put(crtc);
		if (dm_is_crc_source_dprx(source)) {
#ifdef HAVE_DRM_DP_START_CRC
			if (drm_dp_stop_crc(aux)) {
				DRM_DEBUG_DRIVER("dp stop crc failed\n");
				ret = -EINVAL;
				goto cleanup;
			}
#endif
		}
	}

	crtc_state->crc_src = source;

#ifndef HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CRC_SOURCE_2ARGS
	*values_cnt = 3;
#endif
	/* Reset crc_skipped on dm state */
	crtc_state->crc_skip_count = 0;

cleanup:
	if (commit)
		drm_crtc_commit_put(commit);

	drm_modeset_unlock(&crtc->mutex);

	return ret;
}

/**
 * amdgpu_dm_crtc_handle_crc_irq: Report to DRM the CRC on given CRTC.
 * @crtc: DRM CRTC object.
 *
 * This function should be called at the end of a vblank, when the fb has been
 * fully processed through the pipe.
 */
void amdgpu_dm_crtc_handle_crc_irq(struct drm_crtc *crtc)
{
	struct dm_crtc_state *crtc_state;
	struct dc_stream_state *stream_state;
	uint32_t crcs[3];

	if (crtc == NULL)
		return;

	crtc_state = to_dm_crtc_state(crtc->state);
	stream_state = crtc_state->stream;

	/* Early return if CRC capture is not enabled. */
	if (!amdgpu_dm_is_valid_crc_source(crtc_state->crc_src))
		return;

	/*
	 * Since flipping and crc enablement happen asynchronously, we - more
	 * often than not - will be returning an 'uncooked' crc on first frame.
	 * Probably because hw isn't ready yet. For added security, skip the
	 * first two CRC values.
	 */
	if (crtc_state->crc_skip_count < 2) {
		crtc_state->crc_skip_count += 1;
		return;
	}

	if (dm_is_crc_source_crtc(crtc_state->crc_src)) {
		if (!dc_stream_get_crc(stream_state->ctx->dc, stream_state,
				       &crcs[0], &crcs[1], &crcs[2]))
			return;

		drm_crtc_add_crc_entry(crtc, true,
				       drm_crtc_accurate_vblank_count(crtc), crcs);
	}
}
#endif
