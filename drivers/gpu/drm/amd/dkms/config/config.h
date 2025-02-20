/* config/config.h.  Generated from config.h.in by configure.  */
/* config/config.h.in.  Generated from configure.ac by autoheader.  */

/* whether invalidate_range_start() wants 2 args */
#define HAVE_2ARGS_INVALIDATE_RANGE_START 1

/* whether invalidate_range_start() wants 5 args */
/* #undef HAVE_5ARGS_INVALIDATE_RANGE_START */

/* whether access_ok(x, x) is available */
#define HAVE_ACCESS_OK_WITH_TWO_ARGUMENTS 1

/* whether AMDGPU_CHUNK_ID_SCHEDULED_DEPENDENCIES is defined */
#define HAVE_AMDGPU_CHUNK_ID_SCHEDULED_DEPENDENCIES 1

/* hmm support is enabled */
#define HAVE_AMDKCL_HMM_MIRROR_ENABLED 1

/* amd_iommu_pc_supported() is available */
#define HAVE_AMD_IOMMU_PC_SUPPORTED 1

/* arch_io_{reserve/free}_memtype_wc() are available */
#define HAVE_ARCH_IO_RESERVE_FREE_MEMTYPE_WC 1

/* Define to 1 if you have the <asm/fpu/api.h> header file. */
#define HAVE_ASM_FPU_API_H 1

/* Define to 1 if you have the <asm/set_memory.h> header file. */
#define HAVE_ASM_SET_MEMORY_H 1

/* backlight_device_set_brightness() is available */
#define HAVE_BACKLIGHT_DEVICE_SET_BRIGHTNESS 1

/* whether CHUNK_ID_SYNCOBJ_TIMELINE_WAIT_SIGNAL is defined */
#define HAVE_CHUNK_ID_SYNCOBJ_TIMELINE_WAIT_SIGNAL 1

/* whether CHUNK_ID_SYNOBJ_IN_OUT is defined */
#define HAVE_CHUNK_ID_SYNOBJ_IN_OUT 1

/* compat_ptr_ioctl() is available */
#define HAVE_COMPAT_PTR_IOCTL 1

/* devcgroup_check_permission() is available */
#define HAVE_DEVCGROUP_CHECK_PERMISSION 1

/* devm_memremap_pages() wants struct dev_pagemap */
#define HAVE_DEVM_MEMREMAP_PAGES_DEV_PAGEMAP 1

/* devm_memremap_pages() wants p,p,p,p interface */
/* #undef HAVE_DEVM_MEMREMAP_PAGES_P_P_P_P */

/* dev_pm_set_driver_flags() is available */
#define HAVE_DEV_PM_SET_DRIVER_FLAGS 1

/* dma_buf dynamic_mapping is available */
/* #undef HAVE_DMA_BUF_OPS_DYNAMIC_MAPPING */

/* whether dma_fence_get_stub exits */
#define HAVE_DMA_FENCE_GET_STUB 1

/* dma_fence_set_error() is available */
#define HAVE_DMA_FENCE_SET_ERROR 1

/* dma_map_resource() is enabled */
#define HAVE_DMA_MAP_RESOURCE 1

/* dma_map_sgtable() is enabled */
#define HAVE_DMA_MAP_SGTABLE 1

/* dma_resv->seq is available */
#define HAVE_DMA_RESV_SEQ 1

/* dma_resv->seq is seqcount_ww_mutex_t */
#define HAVE_DMA_RESV_SEQCOUNT_WW_MUTEX_T 1

/* down_read_killable() is available */
#define HAVE_DOWN_READ_KILLABLE 1

/* down_write_killable() is available */
#define HAVE_DOWN_WRITE_KILLABLE 1

/* drm_dp_mst_connector_early_unregister() is available */
#define HAVE_DP_MST_CONNECTOR_EARLY_UNREGISTER 1

/* drm_dp_mst_connector_late_register() is available */
#define HAVE_DP_MST_CONNECTOR_LATE_REGISTER 1

/* drm_accurate_vblank_count() is available */
/* #undef HAVE_DRM_ACCURATE_VBLANK_COUNT */

/* DRM_AMDGPU_FENCE_TO_HANDLE is defined */
#define HAVE_DRM_AMDGPU_FENCE_TO_HANDLE 1

/* Define to 1 if you have the <drm/amdgpu_pciid.h> header file. */
/* #undef HAVE_DRM_AMDGPU_PCIID_H */

/* drm_atomic_get_old_crtc_state() and drm_atomic_get_new_crtc_state() are
   available */
#define HAVE_DRM_ATOMIC_GET_CRTC_STATE 1

/* drm_atomic_get_new_plane_state() is available */
#define HAVE_DRM_ATOMIC_GET_NEW_PLANE_STATE 1

/* drm_atomic_helper_check_plane_state() is available */
#define HAVE_DRM_ATOMIC_HELPER_CHECK_PLANE_STATE 1

/* drm_atomic_helper_shutdown() is available */
#define HAVE_DRM_ATOMIC_HELPER_SHUTDOWN 1

/* drm_atomic_helper_wait_for_flip_done() is available */
#define HAVE_DRM_ATOMIC_HELPER_WAIT_FOR_FLIP_DONE 1

/* {drm_atomic_helper_crtc_set_property, drm_atomic_helper_plane_set_property,
   drm_atomic_helper_connector_set_property, drm_atomic_helper_connector_dpms}
   is available */
/* #undef HAVE_DRM_ATOMIC_HELPER_XXX_SET_PROPERTY */

/* drm_atomic_nonblocking_commit() is available */
#define HAVE_DRM_ATOMIC_NONBLOCKING_COMMIT 1

/* drm_atomic_plane_disabling() wants drm_plane_state * arg */
#define HAVE_DRM_ATOMIC_PLANE_DISABLING_DRM_PLANE_STATE 1

/* drm_atomic_private_obj_init() is available */
#define HAVE_DRM_ATOMIC_PRIVATE_OBJ_INIT 1

/* drm_atomic_private_obj_init() has p,p,p,p interface */
#define HAVE_DRM_ATOMIC_PRIVATE_OBJ_INIT_P_P_P_P 1

/* whether struct drm_atomic_state have async_update */
#define HAVE_DRM_ATOMIC_STATE_ASYNC_UPDATE 1

/* drm_atomic_state_put() is available */
#define HAVE_DRM_ATOMIC_STATE_PUT 1

/* whether drm/drm_audio_component.h is defined */
#define HAVE_DRM_AUDIO_COMPONENT_HEADER 1

/* drm_calc_vbltimestamp_from_scanoutpos() drop mode arg */
/* #undef HAVE_DRM_CALC_VBLTIMESTAMP_FROM_SCANOUTPOS_DROP_MOD_ARG */

/* drm_calc_vbltimestamp_from_scanoutpos() have the crtc & mode arg */
/* #undef HAVE_DRM_CALC_VBLTIMESTAMP_FROM_SCANOUTPOS_HAVE_CRTC_MODE_ARG */

/* drm_calc_vbltimestamp_from_scanoutpos() remove crtc arg */
/* #undef HAVE_DRM_CALC_VBLTIMESTAMP_FROM_SCANOUTPOS_HAVE_MODE_ARG */

/* drm_calc_vbltimestamp_from_scanoutpos() use ktime_t arg */
/* #undef HAVE_DRM_CALC_VBLTIMESTAMP_FROM_SCANOUTPOS_USE_KTIMER_T_ARG */

/* drm_color_lut_size() is available */
#define HAVE_DRM_COLOR_LUT_SIZE 1

/* drm_connector_attach_encoder() is available */
#define HAVE_DRM_CONNECTOR_ATTACH_ENCODER 1

/* drm_connector_for_each_possible_encoder() wants 2 arguments */
#define HAVE_DRM_CONNECTOR_FOR_EACH_POSSIBLE_ENCODER_2ARGS 1

/* struct drm_connector_funcs has register members */
#define HAVE_DRM_CONNECTOR_FUNCS_REGISTER 1

/* drm_connector_helper_funcs->atomic_check() wants struct drm_atomic_state
   arg */
#define HAVE_DRM_CONNECTOR_HELPER_FUNCS_ATOMIC_CHECK_ARG_DRM_ATOMIC_STATE 1

/* drm_connector_init_with_ddc() is available */
#define HAVE_DRM_CONNECTOR_INIT_WITH_DDC 1

/* drm_connector_list_iter_begin() is available */
#define HAVE_DRM_CONNECTOR_LIST_ITER_BEGIN 1

/* connector property "max bpc" is available */
#define HAVE_DRM_CONNECTOR_PROPERTY_MAX_BPC 1

/* drm_connector_put() is available */
#define HAVE_DRM_CONNECTOR_PUT 1

/* connector reference counting is available */
#define HAVE_DRM_CONNECTOR_REFERENCE_COUNTING_SUPPORTED 1

/* drm_connector_set_path_property() is available */
#define HAVE_DRM_CONNECTOR_SET_PATH_PROPERTY 1

/* struct drm_connector_state has hdcp_content_type member */
#define HAVE_DRM_CONNECTOR_STATE_HDCP_CONTENT_TYPE 1

/* drm_connector_unreference() is available */
/* #undef HAVE_DRM_CONNECTOR_UNREFERENCE */

/* drm_connector_update_edid_property() is available */
#define HAVE_DRM_CONNECTOR_UPDATE_EDID_PROPERTY 1

/* ddrm_atomic_stat has __drm_crtcs_state */
/* #undef HAVE_DRM_CRTCS_STATE_MEMBER */

/* drm_crtc_accurate_vblank_count() is available */
#define HAVE_DRM_CRTC_ACCURATE_VBLANK_COUNT 1

/* drm_crtc_enable_color_mgmt() is available */
#define HAVE_DRM_CRTC_ENABLE_COLOR_MGMT 1

/* drm_crtc_from_index() is available */
#define HAVE_DRM_CRTC_FROM_INDEX 1

/* drm_crtc_init_with_planes() wants name */
#define HAVE_DRM_CRTC_INIT_WITH_PLANES_VALID_WITH_NAME 1

/* drm_debug_enabled() is available */
#define HAVE_DRM_DEBUG_ENABLED 1

/* drm_debug_printer() function is available */
#define HAVE_DRM_DEBUG_PRINTER 1

/* dev_device->driver_features is available */
#define HAVE_DRM_DEVICE_DRIVER_FEATURES 1

/* drm_device->filelist_mutex is available */
#define HAVE_DRM_DEVICE_FILELIST_MUTEX 1

/* drm_device->open_count is int */
/* #undef HAVE_DRM_DEVICE_OPEN_COUNT_INT */

/* drm_dev_put() is available */
#define HAVE_DRM_DEV_PUT 1

/* drm_dev_unplug() is available */
/* #undef HAVE_DRM_DEV_UNPLUG */

/* display_info->hdmi.scdc.scrambling are available */
#define HAVE_DRM_DISPLAY_INFO_HDMI_SCDC_SCRAMBLING 1

/* display_info->max_tmds_clock is available */
#define HAVE_DRM_DISPLAY_INFO_MAX_TMDS_CLOCK 1

/* drm_dp_atomic_find_vcpi_slots() is available */
#define HAVE_DRM_DP_ATOMIC_FIND_VCPI_SLOTS 1

/* drm_dp_atomic_find_vcpi_slots() wants 5args */
#define HAVE_DRM_DP_ATOMIC_FIND_VCPI_SLOTS_5ARGS 1

/* drm_dp_calc_pbn_mode() wants 3args */
#define HAVE_DRM_DP_CALC_PBN_MODE_3ARGS 1

/* drm_dp_cec* correlation functions are available */
#define HAVE_DRM_DP_CEC_CORRELATION_FUNCTIONS 1

/* drm_dp_cec_register_connector() wants p,p interface */
#define HAVE_DRM_DP_CEC_REGISTER_CONNECTOR_PP 1

/* drm_dp_mst_add_affected_dsc_crtcs() is available */
#define HAVE_DRM_DP_MST_ADD_AFFECTED_DSC_CRTCS 1

/* drm_dp_mst_allocate_vcpi() has p,p,i,i interface */
#define HAVE_DRM_DP_MST_ALLOCATE_VCPI_P_P_I_I 1

/* drm_dp_mst_atomic_check() is available */
#define HAVE_DRM_DP_MST_ATOMIC_CHECK 1

/* drm_dp_mst_atomic_enable_dsc() is available */
#define HAVE_DRM_DP_MST_ATOMIC_ENABLE_DSC 1

/* drm_dp_mst_detect_port() wants p,p,p,p args */
#define HAVE_DRM_DP_MST_DETECT_PORT_PPPP 1

/* drm_dp_mst_dsc_aux_for_port() is available */
#define HAVE_DRM_DP_MST_DSC_AUX_FOR_PORT 1

/* drm_dp_mst_{get,put}_port_malloc() is available */
#define HAVE_DRM_DP_MST_GET_PUT_PORT_MALLOC 1

/* struct drm_dp_mst_topology_cbs has hotplug member */
/* #undef HAVE_DRM_DP_MST_TOPOLOGY_CBS_HOTPLUG */

/* struct drm_dp_mst_topology_cbs->register_connector is available */
/* #undef HAVE_DRM_DP_MST_TOPOLOGY_CBS_REGISTER_CONNECTOR */

/* drm_dp_mst_topology_mgr_init() wants drm_device arg */
#define HAVE_DRM_DP_MST_TOPOLOGY_MGR_INIT_DRM_DEV 1

/* drm_dp_mst_topology_mgr_resume() wants 2 args */
#define HAVE_DRM_DP_MST_TOPOLOGY_MGR_RESUME_2ARGS 1

/* drm_dp_send_real_edid_checksum() is available */
#define HAVE_DRM_DP_SEND_REAL_EDID_CHECKSUM 1

/* drm_dp_start_crc() is available */
#define HAVE_DRM_DP_START_CRC 1

/* drm_driver->gem_prime_res_obj() is available */
/* #undef HAVE_DRM_DRIVER_GEM_PRIME_RES_OBJ */

/* drm_driver->release() is available */
#define HAVE_DRM_DRIVER_RELEASE 1

/* Define to 1 if you have the <drm/drmP.h> header file. */
/* #undef HAVE_DRM_DRMP_H */

/* Define to 1 if you have the <drm/drm_atomic_uapi.h> header file. */
#define HAVE_DRM_DRM_ATOMIC_UAPI_H 1

/* Define to 1 if you have the <drm/drm_auth.h> header file. */
#define HAVE_DRM_DRM_AUTH_H 1

/* Define to 1 if you have the <drm/drm_backport.h> header file. */
/* #undef HAVE_DRM_DRM_BACKPORT_H */

/* Define to 1 if you have the <drm/drm_connector.h> header file. */
#define HAVE_DRM_DRM_CONNECTOR_H 1

/* Define to 1 if you have the <drm/drm_debugfs.h> header file. */
#define HAVE_DRM_DRM_DEBUGFS_H 1

/* Define to 1 if you have the <drm/drm_device.h> header file. */
#define HAVE_DRM_DRM_DEVICE_H 1

/* Define to 1 if you have the <drm/drm_drv.h> header file. */
#define HAVE_DRM_DRM_DRV_H 1

/* Define to 1 if you have the <drm/drm_encoder.h> header file. */
#define HAVE_DRM_DRM_ENCODER_H 1

/* Define to 1 if you have the <drm/drm_file.h> header file. */
#define HAVE_DRM_DRM_FILE_H 1

/* Define to 1 if you have the <drm/drm_gem_framebuffer_helper.h> header file.
   */
#define HAVE_DRM_DRM_GEM_FRAMEBUFFER_HELPER_H 1

/* Define to 1 if you have the <drm/drm_hdcp.h> header file. */
#define HAVE_DRM_DRM_HDCP_H 1

/* Define to 1 if you have the <drm/drm_ioctl.h> header file. */
#define HAVE_DRM_DRM_IOCTL_H 1

/* Define to 1 if you have the <drm/drm_irq.h> header file. */
#define HAVE_DRM_DRM_IRQ_H 1

/* Define to 1 if you have the <drm/drm_managed.h> header file. */
#define HAVE_DRM_DRM_MANAGED_H 1

/* Define to 1 if you have the <drm/drm_plane.h> header file. */
#define HAVE_DRM_DRM_PLANE_H 1

/* Define to 1 if you have the <drm/drm_print.h> header file. */
#define HAVE_DRM_DRM_PRINT_H 1

/* Define to 1 if you have the <drm/drm_probe_helper.h> header file. */
#define HAVE_DRM_DRM_PROBE_HELPER_H 1

/* Define to 1 if you have the <drm/drm_util.h> header file. */
#define HAVE_DRM_DRM_UTIL_H 1

/* Define to 1 if you have the <drm/drm_vblank.h> header file. */
#define HAVE_DRM_DRM_VBLANK_H 1

/* drm_driver_feature DRIVER_IRQ_SHARED is available */
/* #undef HAVE_DRM_DRV_DRIVER_IRQ_SHARED */

/* drm_driver_feature DRIVER_PRIME is available */
/* #undef HAVE_DRM_DRV_DRIVER_PRIME */

/* drm_driver_feature DRIVER_SYNCOBJ_TIMELINE is available */
#define HAVE_DRM_DRV_DRIVER_SYNCOBJ_TIMELINE 1

/* drm_driver->gem_prime_export with p,i arg is available */
#define HAVE_DRM_DRV_GEM_PRIME_EXPORT_PI 1

/* drm_edid_to_eld() are available */
/* #undef HAVE_DRM_EDID_TO_ELD */

/* drm_encoder_find() wants file_priv */
#define HAVE_DRM_ENCODER_FIND_VALID_WITH_FILE 1

/* drm_fb_helper_single_add_all_connectors() &&
   drm_fb_helper_remove_one_connector() are symbol */
/* #undef HAVE_DRM_FB_HELPER_ADD_REMOVE_CONNECTORS */

/* drm_fb_helper_fill_info() is available */
#define HAVE_DRM_FB_HELPER_FILL_INFO 1

/* drm_fb_helper_init() has 2 args */
#define HAVE_DRM_FB_HELPER_INIT_2ARGS 1

/* drm_fb_helper_init() has 3 args */
/* #undef HAVE_DRM_FB_HELPER_INIT_3ARGS */

/* whether drm_fb_helper_lastclose() is available */
#define HAVE_DRM_FB_HELPER_LASTCLOSE 1

/* drm_fb_helper_remove_conflicting_pci_framebuffers() is available */
#define HAVE_DRM_FB_HELPER_REMOVE_CONFLICTING_PCI_FRAMEBUFFERS 1

/* drm_fb_helper_remove_conflicting_pci_framebuffers() wants p,i,p args */
/* #undef HAVE_DRM_FB_HELPER_REMOVE_CONFLICTING_PCI_FRAMEBUFFERS_PIP */

/* drm_fb_helper_remove_conflicting_pci_framebuffers() wants p,p args */
#define HAVE_DRM_FB_HELPER_REMOVE_CONFLICTING_PCI_FRAMEBUFFERS_PP 1

/* drm_fb_helper_set_suspend_unlocked() is available */
#define HAVE_DRM_FB_HELPER_SET_SUSPEND_UNLOCKED 1

/* whether struct drm_framebuffer have format */
#define HAVE_DRM_FRAMEBUFFER_FORMAT 1

/* drm_gem_map_attach() wants 2 arguments */
/* #undef HAVE_DRM_GEM_MAP_ATTACH_2ARGS */

/* drm_gem_object_lookup() wants 2 args */
#define HAVE_DRM_GEM_OBJECT_LOOKUP_2ARGS 1

/* drm_gem_object_put_locked() is available */
#define HAVE_DRM_GEM_OBJECT_PUT_LOCKED 1

/* drm_gem_object_put_unlocked() is available */
/* #undef HAVE_DRM_GEM_OBJECT_PUT_UNLOCKED */

/* ttm_buffer_object->base is available */
#define HAVE_DRM_GEM_OBJECT_RESV 1

/* drm_get_format_info() is available */
#define HAVE_DRM_GET_FORMAT_INFO 1

/* drm_get_format_name() has i,p interface */
#define HAVE_DRM_GET_FORMAT_NAME_I_P 1

/* drm_hdcp_update_content_protection is available */
#define HAVE_DRM_HDCP_UPDATE_CONTENT_PROTECTION 1

/* drm_hdmi_avi_infoframe_from_display_mode() has p,p,b interface */
/* #undef HAVE_DRM_HDMI_AVI_INFOFRAME_FROM_DISPLAY_MODE_P_P_B */

/* drm_hdmi_avi_infoframe_from_display_mode() has p,p,p interface */
#define HAVE_DRM_HDMI_AVI_INFOFRAME_FROM_DISPLAY_MODE_P_P_P 1

/* drm_hdmi_vendor_infoframe_from_display_mode() has p,p,p interface */
#define HAVE_DRM_HDMI_VENDOR_INFOFRAME_FROM_DISPLAY_MODE_P_P_P 1

/* drm_helper_force_disable_all() is available */
#define HAVE_DRM_HELPER_FORCE_DISABLE_ALL 1

/* drm_helper_mode_fill_fb_struct() wants dev arg */
#define HAVE_DRM_HELPER_MODE_FILL_FB_STRUCT_DEV 1

/* drm_is_current_master() is available */
#define HAVE_DRM_IS_CURRENT_MASTER 1

/* drm_kms_helper_is_poll_worker() is available */
#define HAVE_DRM_KMS_HELPER_IS_POLL_WORKER 1

/* whether drm_mm_insert_mode is available */
#define HAVE_DRM_MM_INSERT_MODE 1

/* drm_mm_print() is available */
#define HAVE_DRM_MM_PRINT 1

/* drm_mode_config_funcs->atomic_state_alloc() is available */
#define HAVE_DRM_MODE_CONFIG_FUNCS_ATOMIC_STATE_ALLOC 1

/* drm_mode_config->helper_private is available */
#define HAVE_DRM_MODE_CONFIG_HELPER_PRIVATE 1

/* drm_mode_get_hv_timing is available */
#define HAVE_DRM_MODE_GET_HV_TIMING 1

/* drm_mode_is_420_xxx() is available */
#define HAVE_DRM_MODE_IS_420_XXX 1

/* drm_need_swiotlb() is availablea */
#define HAVE_DRM_NEED_SWIOTLB 1

/* drm atomic nonblocking commit support is available */
#define HAVE_DRM_NONBLOCKING_COMMIT_SUPPORT 1

/* drm_plane_helper_check_state is available */
/* #undef HAVE_DRM_PLANE_HELPER_CHECK_STATE */

/* drm_plane_create_alpha_property, drm_plane_create_blend_mode_property are
   available */
#define HAVE_DRM_PLANE_PROPERTY_ALPHA_BLEND_MODE 1

/* drm_plane_create_color_properties is available */
#define HAVE_DRM_PLANE_PROPERTY_COLOR_ENCODING_RANGE 1

/* drm_plane_create_rotation_property is available */
#define HAVE_DRM_PLANE_PROPERTY_ROTATION 1

/* drm_syncobj_fence_get() is available */
/* #undef HAVE_DRM_SYNCOBJ_FENCE_GET */

/* drm_syncobj_find_fence() is available */
#define HAVE_DRM_SYNCOBJ_FIND_FENCE 1

/* whether drm_syncobj_find_fence() wants 3 args */
/* #undef HAVE_DRM_SYNCOBJ_FIND_FENCE_3ARGS */

/* whether drm_syncobj_find_fence() wants 4 args */
/* #undef HAVE_DRM_SYNCOBJ_FIND_FENCE_4ARGS */

/* whether drm_syncobj_find_fence() wants 5 args */
#define HAVE_DRM_SYNCOBJ_FIND_FENCE_5ARGS 1

/* Define to 1 if you have the <drm/task_barrier.h> header file. */
#define HAVE_DRM_TASK_BARRIER_H 1

/* drm_universal_plane_init() wants 7 args */
/* #undef HAVE_DRM_UNIVERSAL_PLANE_INIT_7ARGS */

/* drm_universal_plane_init() wants 8 args */
/* #undef HAVE_DRM_UNIVERSAL_PLANE_INIT_8ARGS */

/* drm_universal_plane_init() wants 9 args */
#define HAVE_DRM_UNIVERSAL_PLANE_INIT_9ARGS 1

/* drm_vma_node_verify_access() 2nd argument is drm_file */
#define HAVE_DRM_VMA_NODE_VERIFY_ACCESS_HAS_DRM_FILE 1

/* Variable refresh rate(vrr) is supported */
#define HAVE_DRM_VRR_SUPPORTED 1

/* fault_flag_allow_retry_first() is available */
#define HAVE_FAULT_FLAG_ALLOW_RETRY_FIRST 1

/* drm_mode_object->free_cb is available */
/* #undef HAVE_FREE_CB_IN_STRUCT_DRM_MODE_OBJECT */

/* drm_driver->gem_free_object_unlocked() is available */
#define HAVE_GEM_FREE_OBJECT_UNLOCKED_IN_DRM_DRIVER 1

/* get_scanout_position has struct drm_display_mode arg */
/* #undef HAVE_GET_SCANOUT_POSITION_HAS_DRM_DISPLAY_MODE_ARG */

/* get_scanout_position has timestamp arg */
/* #undef HAVE_GET_SCANOUT_POSITION_HAS_TIMESTAMP_ARG */

/* get_scanout_position return bool */
/* #undef HAVE_GET_SCANOUT_POSITION_RETURN_BOOL */

/* get_user_pages() wants 6 args */
/* #undef HAVE_GET_USER_PAGES_6ARGS */

/* get_user_pages() wants gup_flags parameter */
#define HAVE_GET_USER_PAGES_GUP_FLAGS 1

/* get_user_pages_remote() wants gup_flags parameter */
/* #undef HAVE_GET_USER_PAGES_REMOTE_GUP_FLAGS */

/* get_user_pages_remote() is introduced with initial prototype */
/* #undef HAVE_GET_USER_PAGES_REMOTE_INTRODUCED */

/* get_user_pages_remote() wants locked parameter */
/* #undef HAVE_GET_USER_PAGES_REMOTE_LOCKED */

/* get_user_pages_remote() remove task_struct pointer */
#define HAVE_GET_USER_PAGES_REMOTE_REMOVE_TASK_STRUCT 1

/* get_vblank_timestamp has bool in_vblank_irq arg */
/* #undef HAVE_GET_VBLANK_TIMESTAMP_IN_DRM_DRIVER_HAS_BOOL_IN_VBLANK_IRQ */

/* get_vblank_timestamp has ktime_t arg */
/* #undef HAVE_GET_VBLANK_TIMESTAMP_IN_DRM_DRIVER_HAS_KTIME_T */

/* get_vblank_timestamp return bool */
/* #undef HAVE_GET_VBLANK_TIMESTAMP_IN_DRM_DRIVER_RETURN_BOOL */

/* drm_connector_hdr_sink_metadata() is available */
#define HAVE_HDR_SINK_METADATA 1

/* hmm remove the customizable pfn format */
#define HAVE_HMM_DROP_CUSTOMIZABLE_PFN_FORMAT 1

/* hmm_range_fault() wants 1 arg */
#define HAVE_HMM_RANGE_FAULT_1ARG 1

/* struct i2c_lock_operations is defined */
#define HAVE_I2C_LOCK_OPERATIONS_STRUCT 1

/* i2c_new_client_device() is enabled */
#define HAVE_I2C_NEW_CLIENT_DEVICE 1

/* idr_remove return void pointer */
#define HAVE_IDR_REMOVE_RETURN_VOID_POINTER 1

/* in_compat_syscall is defined */
#define HAVE_IN_COMPAT_SYSCALL 1

/* jiffies64_to_msecs() is available */
#define HAVE_JIFFIES64_TO_MSECS 1

/* kallsyms_lookup_name is available */
/* #undef HAVE_KALLSYMS_LOOKUP_NAME */

/* kref_read() function is available */
#define HAVE_KREF_READ 1

/* ksys_sync_helper() is available */
#define HAVE_KSYS_SYNC_HELPER 1

/* kthread_{park/unpark/parkme/should_park}() is available */
#define HAVE_KTHREAD_PARK_XX 1

/* kthread_{use,unuse}_mm() is available */
#define HAVE_KTHREAD_USE_MM 1

/* ktime_get_boottime_ns() is available */
#define HAVE_KTIME_GET_BOOTTIME_NS 1

/* ktime_get_mono_fast_ns is available */
#define HAVE_KTIME_GET_MONO_FAST_NS 1

/* ktime_get_ns is available */
#define HAVE_KTIME_GET_NS 1

/* ktime_get_raw_ns is available */
#define HAVE_KTIME_GET_RAW_NS 1

/* ktime_get_real_seconds() is available */
#define HAVE_KTIME_GET_REAL_SECONDS 1

/* kvcalloc() is available */
#define HAVE_KVCALLOC 1

/* kvfree() is available */
#define HAVE_KVFREE 1

/* kvmalloc_array() is available */
#define HAVE_KVMALLOC_ARRAY 1

/* kv[mz]alloc() are available */
#define HAVE_KVZALLOC_KVMALLOC 1

/* Define to 1 if you have the <linux/bits.h> header file. */
#define HAVE_LINUX_BITS_H 1

/* Define to 1 if you have the <linux/compiler_attributes.h> header file. */
#define HAVE_LINUX_COMPILER_ATTRIBUTES_H 1

/* Define to 1 if you have the <linux/dma-attrs.h> header file. */
/* #undef HAVE_LINUX_DMA_ATTRS_H */

/* Define to 1 if you have the <linux/dma-fence.h> header file. */
#define HAVE_LINUX_DMA_FENCE_H 1

/* Define to 1 if you have the <linux/dma-resv.h> header file. */
#define HAVE_LINUX_DMA_RESV_H 1

/* Define to 1 if you have the <linux/fence-array.h> header file. */
/* #undef HAVE_LINUX_FENCE_ARRAY_H */

/* Define to 1 if you have the <linux/io-64-nonatomic-lo-hi.h> header file. */
#define HAVE_LINUX_IO_64_NONATOMIC_LO_HI_H 1

/* Define to 1 if you have the <linux/kfifo-new.h> header file. */
/* #undef HAVE_LINUX_KFIFO_NEW_H */

/* Define to 1 if you have the <linux/mem_encrypt.h> header file. */
#define HAVE_LINUX_MEM_ENCRYPT_H 1

/* Define to 1 if you have the <linux/mmap_lock.h> header file. */
#define HAVE_LINUX_MMAP_LOCK_H 1

/* Define to 1 if you have the <linux/nospec.h> header file. */
#define HAVE_LINUX_NOSPEC_H 1

/* Define to 1 if you have the <linux/overflow.h> header file. */
#define HAVE_LINUX_OVERFLOW_H 1

/* Define to 1 if you have the <linux/pci-p2pdma.h> header file. */
#define HAVE_LINUX_PCI_P2PDMA_H 1

/* Define to 1 if you have the <linux/sched/mm.h> header file. */
#define HAVE_LINUX_SCHED_MM_H 1

/* Define to 1 if you have the <linux/sched/signal.h> header file. */
#define HAVE_LINUX_SCHED_SIGNAL_H 1

/* Define to 1 if you have the <linux/sched/task.h> header file. */
#define HAVE_LINUX_SCHED_TASK_H 1

/* list_bulk_move_tail() is available */
#define HAVE_LIST_BULK_MOVE_TAIL 1

/* list_is_first() is available */
#define HAVE_LIST_IS_FIRST 1

/* list_rotate_to_front() is available */
#define HAVE_LIST_ROTATE_TO_FRONT 1

/* memalloc_nofs_{save,restore}() are available */
#define HAVE_MEMALLOC_NOFS_SAVE 1

/* mem_encrypt_active() is available */
#define HAVE_MEM_ENCRYPT_ACTIVE 1

/* mmgrab() is available in linux/sched.h */
#define HAVE_MMGRAB 1

/* mmu_notifier_call_srcu() is available */
/* #undef HAVE_MMU_NOTIFIER_CALL_SRCU */

/* mmu_notifier_put() is available */
#define HAVE_MMU_NOTIFIER_PUT 1

/* mmu_notifier_range_blockable() is available */
#define HAVE_MMU_NOTIFIER_RANGE_BLOCKABLE 1

/* mmu_notifier_synchronize() is available */
#define HAVE_MMU_NOTIFIER_SYNCHRONIZE 1

/* mm_access() is available */
#define HAVE_MM_ACCESS 1

/* release_pages() wants 2 args */
#define HAVE_MM_RELEASE_PAGES_2ARGS 1

/* num_u32_u32 is available */
#define HAVE_MUL_U32_U32 1

/* pcie_bandwidth_available() is available */
#define HAVE_PCIE_BANDWIDTH_AVAILABLE 1

/* pci_enable_atomic_ops_to_root() exist */
#define HAVE_PCIE_ENABLE_ATOMIC_OPS_TO_ROOT 1

/* pcie_get_speed_cap() and pcie_get_width_cap() exist */
#define HAVE_PCIE_GET_SPEED_AND_WIDTH_CAP 1

/* PCI driver handles extended tags */
#define HAVE_PCI_CONFIGURE_EXTENDED_TAGS 1

/* pci_dev_id() is available */
#define HAVE_PCI_DEV_ID 1

/* pci_is_thunderbolt_attached() is available */
#define HAVE_PCI_IS_THUNDERBOLD_ATTACHED 1

/* pci_upstream_bridge() is available */
#define HAVE_PCI_UPSTREAM_BRIDGE 1

/* perf_event_update_userpage() is exported */
#define HAVE_PERF_EVENT_UPDATE_USERPAGE 1

/* pfn_t is defined */
#define HAVE_PFN_T 1

/* vm_insert_mixed() wants pfn_t arg */
/* #undef HAVE_PFN_T_VM_INSERT_MIXED */

/* pm_genpd_remove_device() wants 2 arguments */
/* #undef HAVE_PM_GENPD_REMOVE_DEVICE_2ARGS */

/* remove_conflicting_framebuffers() returns int */
/* #undef HAVE_REMOVE_CONFLICTING_FRAMEBUFFERS_RETURNS_INT */

/* request_firmware_direct() is available */
#define HAVE_REQUEST_FIRMWARE_DIRECT 1

/* reservation_object->staged is available */
/* #undef HAVE_RESERVATION_OBJECT_STAGED */

/* sched_set_fifo_low() is available */
#define HAVE_SCHED_SET_FIFO_LOW 1

/* seq_hex_dump() is available */
#define HAVE_SEQ_HEX_DUMP 1

/* drm_driver->set_busid is available */
/* #undef HAVE_SET_BUSID_IN_STRUCT_DRM_DRIVER */

/* whether si_mem_available() is available */
#define HAVE_SI_MEM_AVAILABLE 1

/* strscpy() is available */
#define HAVE_STRSCPY 1

/* struct dma_buf_ops->allow_peer2peer is available */
/* #undef HAVE_STRUCT_DMA_BUF_OPS_ALLOW_PEER2PEER */

/* struct dma_buf_ops->pin() is available */
#define HAVE_STRUCT_DMA_BUF_OPS_PIN 1

/* drm_connector->ycbcr_420_allowed is available */
#define HAVE_STRUCT_DRM_CONNECTOR_YCBCR_420_ALLOWED 1

/* drm_crtc_funcs->enable_vblank() is available */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_ENABLE_VBLANK 1

/* crtc->funcs->gamma_set() wants 5 args */
/* #undef HAVE_STRUCT_DRM_CRTC_FUNCS_GAMMA_SET_5ARGS */

/* crtc->funcs->gamma_set() wants 6 args */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_GAMMA_SET_6ARGS 1

/* struct drm_crtc_funcs->get_vblank_timestamp() is available */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_GET_VBLANK_TIMESTAMP 1

/* drm_crtc_funcs->{get,verify}_crc_sources() is available */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_GET_VERIFY_CRC_SOURCES 1

/* drm_crtc_funcs->page_flip_target() is available */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_PAGE_FLIP_TARGET 1

/* drm_crtc_funcs->page_flip_target() wants ctx parameter */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_PAGE_FLIP_TARGET_CTX 1

/* drm_crtc_funcs->set_config() wants ctx parameter */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CONFIG_CTX 1

/* crtc->funcs->set_crc_source() is available */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CRC_SOURCE 1

/* crtc->funcs->set_crc_source() wants 2 args */
#define HAVE_STRUCT_DRM_CRTC_FUNCS_SET_CRC_SOURCE_2ARGS 1

/* struct drm_crtc_state->async_flip is available */
#define HAVE_STRUCT_DRM_CRTC_STATE_ASYNC_FLIP 1

/* struct drm_crtc_state has flag for flip */
#define HAVE_STRUCT_DRM_CRTC_STATE_FLIP_FLAG 1

/* struct drm_crtc_state->pageflip_flags is available */
/* #undef HAVE_STRUCT_DRM_CRTC_STATE_PAGEFLIP_FLAGS */

/* drm_pending_vblank_event->sequence is available */
#define HAVE_STRUCT_DRM_PENDING_VBLANK_EVENT_SEQUENCE 1

/* drm_plane_helper_funcs->atomic_async_check() is available */
#define HAVE_STRUCT_DRM_PLANE_HELPER_FUNCS_ATOMIC_ASYNC_CHECK 1

/* drm_plane_helper_funcs->prepare_fb() wants const p arg */
/* #undef HAVE_STRUCT_DRM_PLANE_HELPER_FUNCS_PREPARE_FB_CONST */

/* drm_plane_helper_funcs->prepare_fb() wants p,p arg */
#define HAVE_STRUCT_DRM_PLANE_HELPER_FUNCS_PREPARE_FB_PP 1

/* zone->managed_pages is available */
/* #undef HAVE_STRUCT_ZONE_MANAGED_PAGES */

/* timer_setup() is available */
#define HAVE_TIMER_SETUP 1

/* interval_tree_insert have struct rb_root_cached */
#define HAVE_TREE_INSERT_HAVE_RB_ROOT_CACHED 1

/* ttm_sg_tt_init() is available */
#define HAVE_TTM_SG_TT_INIT 1

/* __poll_t is available */
#define HAVE_TYPE__POLL_T 1

/* Define to 1 if you have the <uapi/linux/sched/types.h> header file. */
#define HAVE_UAPI_LINUX_SCHED_TYPES_H 1

/* vga_switcheroo_set_dynamic_switch() exist */
/* #undef HAVE_VGA_SWITCHEROO_SET_DYNAMIC_SWITCH */

/* get_scanout_position use unsigned int pipe */
/* #undef HAVE_VGA_USE_UNSIGNED_INT_PIPE */

/* vmf_insert_*() are available */
#define HAVE_VMF_INSERT 1

/* vmf_insert_mixed_prot() is available */
#define HAVE_VMF_INSERT_MIXED_PROT 1

/* vmf_insert_pfn_{pmd,pud}() wants 3 args */
/* #undef HAVE_VMF_INSERT_PFN_PMD_3ARGS */

/* vmf_insert_pfn_{pmd,pud}_prot() is available */
#define HAVE_VMF_INSERT_PFN_PMD_PROT 1

/* vmf_insert_pfn_prot() is available */
#define HAVE_VMF_INSERT_PFN_PROT 1

/* vmf_insert_pfn_pud() is available */
/* #undef HAVE_VMF_INSERT_PFN_PUD */

/* vm_fault->{address/vam} is available */
#define HAVE_VM_FAULT_ADDRESS_VMA 1

/* vm_insert_pfn_prot() is available */
/* #undef HAVE_VM_INSERT_PFN_PROT */

/* vm_operations_struct->fault() wants 1 arg */
#define HAVE_VM_OPERATIONS_STRUCT_FAULT_1ARG 1

/* wait_queue_entry_t exists */
#define HAVE_WAIT_QUEUE_ENTRY 1

/* zone_managed_pages() is available */
#define HAVE_ZONE_MANAGED_PAGES 1

/* __drm_atomic_helper_connector_destroy_state() wants 1 arg */
#define HAVE___DRM_ATOMIC_HELPER_CONNECTOR_DESTROY_STATE_P 1

/* __drm_atomic_helper_crtc_destroy_state() wants 1 arg */
#define HAVE___DRM_ATOMIC_HELPER_CRTC_DESTROY_STATE_P 1

/* __drm_atomic_helper_crtc_reset() is available */
#define HAVE___DRM_ATOMIC_HELPER_CRTC_RESET 1

/* __kthread_should_park() is available */
#define HAVE___KTHREAD_SHOULD_PARK 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "amdgpu-dkms"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "amdgpu-dkms 19.40"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "amdgpu-dkms"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "19.40"

/* drm_plane_mask is available */
#define HAVE_DRM_PLANE_MASK 1

/* __print_array for trace is available */
#define HAVE___PRINT_ARRAY 1

/* acpi_put_table() is available */
#define HAVE_ACPI_PUT_TABLE 1

/* drm_atomic_helper_calc_timestamping_constants() is available*/
#define HAVE_DRM_ATOMIC_HELPER_CALC_TIMESTAMPING_CONSTANTS 1

/* block_w and block_h field is available in struct drm_format_info */
#define HAVE_DRM_FORMAT_INFO_MODIFIER_SUPPORTED 1

/* drm_dev_dbg() is exported from drm_print.c */
#define HAVE_DRM_DEV_DBG 1

/* pci_pr3_present() is exported from pci.c */
#define HAVE_PCI_PR3_PRESENT 1

/* struct drm_connector_state->colorspace is available */
#define HAVE_STRUCT_DRM_CONNECTOR_STATE_COLORSPACE 1

/* struct drm_crtc_state->self_refresh_active is available */
#define HAVE_STRUCT_DRM_CONNECTOR_STATE_SELF_REFRESH_AWARE 1

/* struct drm_atomic_state->duplicated is available */
#define HAVE_STRUCT_DRM_ATOMIC_STATE_DUPLICATED 1
