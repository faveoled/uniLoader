// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2022, Ivaylo Ivanov <ivo.ivanov.ivanov1@gmail.com>
 * Copyright (c) 2026, Igor Belwon <igor.belwon@mentallysanemainliners.org>
 */

#include <lib/debug.h>
#include <main/boot.h>
#include <string.h>

void arch_load_kernel(void* kernel, void* dt, void* ramdisk)
{
	/* Verify kernel memory alignment */
	if ((unsigned long)kernel & (0x200000 - 1)) {
		printk(KERN_WARNING, "WARNING: Kernel is not 2MB aligned! (addr: %p)\n", kernel);
	}

#ifndef CONFIG_RAMDISK_NO_COPY
	__optimized_memcpy((void*)CONFIG_RAMDISK_ENTRY, ramdisk, (unsigned long) &ramdisk_size);
#endif
	load_kernel_and_jump(dt, 0, 0, 0, kernel);
}
