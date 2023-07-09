/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"
#include "gpio.h"

const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET(BTN0_NODE, gpios);
const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET(BTN1_NODE, gpios);

void thread_photo(void)
{
	while (1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(500);
	}
}

/**
 * @brief initialize the GPIO pins.
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
uint8_t gpio_init(void)
{
    int ret = 0;
    if (!device_is_ready(led.port) ||
		!device_is_ready(button0.port) ||
		!device_is_ready(button1.port)) {
		return -1;
	}
	ret |= gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
	ret |= gpio_pin_configure_dt(&button0, GPIO_INPUT);
	ret |= gpio_pin_configure_dt(&button1, GPIO_INPUT);

    return ret;
}