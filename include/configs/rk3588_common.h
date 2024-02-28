/* SPDX-License-Identifier:     GPL-2.0+ */
/*
 * (C) Copyright 2021 Rockchip Electronics Co., Ltd
 * Copyright (c) 2023 Edgeble AI Technologies Pvt. Ltd.
 */

#ifndef __CONFIG_RK3588_COMMON_H
#define __CONFIG_RK3588_COMMON_H

#include "rockchip-common.h"

#define CFG_IRAM_BASE			0xff000000

#define CFG_SYS_SDRAM_BASE		0
#define SDRAM_MAX_SIZE			0xf0000000

#define ENV_MEM_LAYOUT_SETTINGS		\
	"scriptaddr=0x00c00000\0"	\
	"script_offset_f=0xffe000\0"	\
	"script_size_f=0x2000\0"	\
	"pxefile_addr_r=0x00e00000\0"	\
	"kernel_addr_r=0x02000000\0"	\
	"kernel_comp_addr_r=0x0a000000\0"	\
	"fdt_addr_r=0x12000000\0"	\
	"fdtoverlay_addr_r=0x12100000\0"	\
	"ramdisk_addr_r=0x12180000\0"	\
	"ramdisk_addr_r_temp=-\0"	\
	"kernel_comp_size=0x8000000\0"  \
	"mmc_dev=1\0" \
	"mmcpart=3\0" 
	"rootdev=\"/dev/mmbclk${mmc_dev}p${mmcpart}\"\0" \

#define CFG_EXTRA_ENV_SETTINGS \
	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"partitions=" PARTS_DEFAULT		\
	ENV_MEM_LAYOUT_SETTINGS			\
	ROCKCHIP_DEVICE_SETTINGS \
	"kernel_name=/boot/Image\0"		\
	"mmcargs=setenv bootargs root=${rootdev} init=/sbin/init rw rootwait;\0"		\
	BOOT_SETTINGS \
	"boot_targets=" BOOT_TARGETS "\0"

#define BOOT_SETTINGS \ 
	"load_fdt= " \
		"load mmc ${mmc_dev}:${mmcpart} ${fdt_addr_r} /boot/${fdtfile} ${fdt_load_args};\0" \
	"load_kernel= " \
		"load mmc ${mmc_dev}:${mmcpart} ${kernel_addr_r} ${kernel_name} ${kernel_load_args};\0" \
	"custom_boot= " \
		"mmc dev ${mmc_dev}; " \
		"run load_fdt; " \
		"run load_kernel; " \
		"run mmcargs; " \
		"booti ${kernel_addr_r} ${ramdisk_addr_r_temp} ${fdt_addr_r}; \0" 


#endif /* __CONFIG_RK3588_COMMON_H */