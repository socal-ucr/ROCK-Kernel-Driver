ifndef CONFIG_DRM
$(error CONFIG_DRM disabled, exit...)
endif

ifeq (y,$(CONFIG_DRM_AMDGPU))
$(error DRM_AMDGPU is built-in, exit...)
endif

ifndef CONFIG_KALLSYMS
$(error CONFIG_KALLSYMS disabled, kallsyms_lookup_name() is absent, exit...)
endif

_is_kcl_macro_defined=$(shell grep $1 $(src)/amd/dkms/config/config.h | grep -q "define" && echo "y" || echo "n")

ifeq ($(call _is_kcl_macro_defined,HAVE_DMA_RESV_SEQ),n)
$(error dma_resv->seq is missing., exit...)
endif

ifdef CONFIG_CC_IS_GCC
GCCMAJ=$(shell echo __GNUC__ | $(CC) -E -x c - | tail -n 1)
GCCMIN=$(shell echo __GNUC_MINOR__ | $(CC) -E -x c - | tail -n 1)
GCCPAT=$(shell echo __GNUC_MINOR__ | $(CC) -E -x c - | tail -n 1)
# CONFIG_GCC_VERSION returns x.xx.xx as the version format
GCCSTR=$(shell printf "%d%02d%02d" $(GCCMAJ) $(GCCMIN) $(GCCPAT))
ifeq ($(shell [ $(CONFIG_GCC_VERSION) -ne $(GCCSTR) ] && echo y), y)
$(warning "Local GCC version $(GCCSTR) does not match kernel compiler GCC version $(CONFIG_GCC_VERSION)")
$(warning "This may cause unexpected and hard-to-isolate compiler-related issues")
endif
endif

DRM_VER=$(shell sed -n 's/^RHEL_DRM_VERSION = \(.*\)/\1/p' $(srctree)/Makefile)
DRM_PATCH=$(shell sed -n 's/^RHEL_DRM_PATCHLEVEL = \(.*\)/\1/p' $(srctree)/Makefile)
ifeq ($(DRM_VER),)
DRM_VER = $(VERSION)
DRM_PATCH = $(PATCHLEVEL)
endif

subdir-ccflags-y += \
	-DDRM_VER=$(DRM_VER) \
	-DDRM_PATCH=$(DRM_PATCH) \
	-DDRM_SUB="0"

define get_rhel_version
printf "#include <linux/version.h>\n$(1)" | $(CC) $(LINUXINCLUDE) -E -x c - | tail -n 1 | grep -v $(1)
endef
RHEL_MAJOR := $(shell $(call get_rhel_version,RHEL_MAJOR))
RHEL_MINOR := $(shell $(call get_rhel_version,RHEL_MINOR))

ifneq (,$(RHEL_MAJOR))
OS_NAME = "rhel"
OS_VERSION = "$(RHEL_MAJOR).$(RHEL_MINOR)"
else ifneq (,$(wildcard /etc/os-release))
OS_NAME = "$(shell sed -n 's/^ID=\(.*\)/\1/p' /etc/os-release | tr -d '\"')"
# On CentOS/RHEL, users could have installed a kernel not distributed from RHEL
ifeq ("centos",$(OS_NAME))
OS_NAME="custom-rhel"
else ifeq ("rhel",$(OS_NAME))
OS_NAME="custom-rhel"
else
ifeq ("linuxmint",$(OS_NAME))
OS_NAME="ubuntu"
endif
OS_VERSION = $(shell sed -n 's/^VERSION_ID=\(.*\)/\1/p' /etc/os-release)
endif
else
OS_NAME = "unknown"
OS_VERSION = "0.0"
endif

ifeq ("ubuntu",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_UBUNTU
else ifeq ("rhel",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_RHEL
else ifeq ("steamos",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_STEAMOS
else ifeq ("sled",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_SLE
else ifeq ("sles",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_SLE
else ifeq ("amzn",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_AMZ
else ifeq ("debian",$(OS_NAME))
subdir-ccflags-y += -DOS_NAME_DEBIAN
else
subdir-ccflags-y += -DOS_NAME_UNKNOWN
endif

subdir-ccflags-y += \
	-DOS_VERSION_MAJOR=$(shell echo $(OS_VERSION).0 | cut -d. -f1) \
	-DOS_VERSION_MINOR=$(shell echo $(OS_VERSION).0 | cut -d. -f2)

ifeq ($(OS_NAME),"opensuse-leap")
ifeq ($(OS_VERSION),"15.2")
subdir-ccflags-y += -DOS_NAME_SUSE_15_2
endif
endif

ifeq ($(OS_NAME),"opensuse-leap")
ifeq ($(OS_VERSION),"15.1")
subdir-ccflags-y += -DOS_NAME_SUSE_15_1
endif
endif

ifeq ($(OS_NAME),"sled")
ifeq ($(OS_VERSION),"15.2")
subdir-ccflags-y += -DOS_NAME_SUSE_15_2
endif
endif

ifeq ($(OS_NAME),"sled")
ifeq ($(OS_VERSION),"15.1")
subdir-ccflags-y += -DOS_NAME_SUSE_15_1
endif
endif

ifeq ($(OS_NAME),"sles")
ifeq ($(OS_VERSION),"15.2")
subdir-ccflags-y += -DOS_NAME_SUSE_15_2
endif
endif

ifeq ($(OS_NAME),"sles")
ifeq ($(OS_VERSION),"15.1")
subdir-ccflags-y += -DOS_NAME_SUSE_15_1
endif
endif

ifeq ($(OS_NAME),"sled")
ifeq ($(OS_VERSION),"12.3")
subdir-ccflags-y += -DOS_NAME_SLE_12_3
endif
endif

ifeq ($(OS_NAME),"sles")
ifeq ($(OS_VERSION),"12.3")
subdir-ccflags-y += -DOS_NAME_SLE_12_3
endif
endif

ifeq ($(OS_NAME),"ubuntu")
OS_BUILD_NUM = $(shell echo $(KERNELRELEASE) | cut -d '-' -f 2)
subdir-ccflags-y += -DUBUNTU_BUILD_NUM=$(OS_BUILD_NUM)
OS_OEM = "$(shell echo $(KERNELRELEASE) | cut -d '-' -f 3)"
ifeq ($(OS_OEM),"oem")
subdir-ccflags-y += -DOS_NAME_UBUNTU_OEM
endif
ifeq ($(OS_VERSION),"14.04")
subdir-ccflags-y += -DOS_NAME_UBUNTU_1404
else
subdir-ccflags-y += -DOS_NAME_UBUNTU_1604
endif
endif

ifeq ($(OS_NAME),"rhel")
ifeq ($(OS_VERSION),"6.8")
subdir-ccflags-y += -DOS_NAME_RHEL_6
else ifeq ($(OS_VERSION),"6.9")
subdir-ccflags-y += -DOS_NAME_RHEL_6
else ifeq ($(OS_VERSION),"6.10")
subdir-ccflags-y += -DOS_NAME_RHEL_6
else ifeq ($(OS_VERSION),"7.2")
subdir-ccflags-y += -DOS_NAME_RHEL_7_2
else ifeq ($(OS_VERSION),"7.3")
subdir-ccflags-y += -DOS_NAME_RHEL_7_3
else ifeq ($(OS_VERSION),"7.4")
subdir-ccflags-y += -DOS_NAME_RHEL_7_4
subdir-ccflags-y += -DOS_NAME_RHEL_7_X
else ifeq ($(OS_VERSION),"7.5")
subdir-ccflags-y += -DOS_NAME_RHEL_7_5
subdir-ccflags-y += -DOS_NAME_RHEL_7_X
else ifeq ($(OS_VERSION),"7.6")
subdir-ccflags-y += -DOS_NAME_RHEL_7_6
subdir-ccflags-y += -DOS_NAME_RHEL_7_X
else ifeq ($(OS_VERSION),"7.7")
subdir-ccflags-y += -DOS_NAME_RHEL_7_7
subdir-ccflags-y += -DOS_NAME_RHEL_7_X
else ifeq ($(OS_VERSION),"8.0")
subdir-ccflags-y += -DOS_NAME_RHEL_8_0
endif
ifneq ($(RHEL_MAJOR),8)
subdir-ccflags-y += \
	-include /usr/src/kernels/$(KERNELRELEASE)/include/drm/drm_backport.h
endif
endif

export OS_NAME OS_VERSION

LINUXINCLUDE := \
	-I$(src)/include \
	-I$(src)/include/uapi \
	-include $(src)/include/kcl/kcl_version.h \
	-include $(src)/include/rename_symbol.h \
	$(LINUXINCLUDE)

export CONFIG_HSA_AMD=y
export CONFIG_DRM_TTM=m
export CONFIG_DRM_TTM_DMA_PAGE_POOL=y
export CONFIG_DRM_AMDGPU=m
export CONFIG_DRM_SCHED=m
export CONFIG_DRM_AMDGPU_CIK=y
export CONFIG_DRM_AMDGPU_SI=y
export CONFIG_DRM_AMDGPU_USERPTR=y
export CONFIG_DRM_AMD_DC=y
export CONFIG_DRM_AMD_DC_DCN1_0=y
export CONFIG_DRM_AMD_DC_DCN1_01=y

subdir-ccflags-y += -DCONFIG_HSA_AMD
subdir-ccflags-y += -DCONFIG_DRM_TTM_DMA_PAGE_POOL
subdir-ccflags-y += -DCONFIG_DRM_AMDGPU_CIK
subdir-ccflags-y += -DCONFIG_DRM_AMDGPU_SI
subdir-ccflags-y += -DCONFIG_DRM_AMDGPU_USERPTR
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC_DCN1_0
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC_DCN1_01

ifeq ($(call _is_kcl_macro_defined,HAVE_DRM_DRM_HDCP_H),y)
export CONFIG_DRM_AMD_DC_HDCP=y
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC_HDCP
endif

# Trying to enable DCN2/3 with core2 optimizations will result in
# older versions of GCC hanging during building/installing. Check
# if the compiler is using core2 optimizations and only build DCN2/3
# if core2 isn't in the compiler flags
ifeq ($(filter %core2, $(KBUILD_CFLAGS)),)
export CONFIG_DRM_AMD_DC_DCN2_x=y
export CONFIG_DRM_AMD_DC_DCN3_x=y
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC_DCN2_x
subdir-ccflags-y += -DCONFIG_DRM_AMD_DC_DCN3_x
endif

obj-m += scheduler/ amd/amdgpu/ ttm/ amd/amdkcl/
