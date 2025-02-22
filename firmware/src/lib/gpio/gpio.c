/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "../lib.h"
#include "gpio.h"

const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET(BUTTON0_NODE, gpios);
const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET(BUTTON1_NODE, gpios);

static struct gpio_callback button_cb_data;

void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins) {
	printk("hi from btn0 callback!\n");
	gpio_pin_toggle_dt(&led);
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
	if (!device_is_ready(led.port) || !device_is_ready(button0.port) || 
			!device_is_ready(button1.port)) {
		return -1;
	}
	ret |= gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
	ret |= gpio_pin_configure_dt(&button0, GPIO_INPUT);
	ret |= gpio_pin_configure_dt(&button1, GPIO_INPUT);

	ret |= gpio_pin_interrupt_configure_dt(&button0, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&button_cb_data, button_pressed, BIT(button0.pin));
	//gpio_add_callback(button0.port, &button_cb_data);

	return ret;
}
