/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, faveoled <faveoled@yandex.com>
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

// Early initialization
int daisy_init(void)
{
	return 0;
}

#ifdef CONFIG_SIMPLE_FB
static struct video_info daisy_fb = {
	.format = FB_FORMAT_RGB888,
	.width = 1080,
	.height = 2280,
	.stride = 3,
	.address = (void *)0x90001000
};
#endif

int daisy_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &daisy_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "xiaomi-daisy",
	.ops = {
		.early_init = daisy_init,
		.drivers_init = daisy_drv,
	},
	.quirks = 0
};
