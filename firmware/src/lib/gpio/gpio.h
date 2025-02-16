/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#include "../lib.h"
#include <zephyr/drivers/gpio.h>

#define LED0_NODE		DT_NODELABEL(led0)
#define BUTTON0_NODE		DT_NODELABEL(button0)
#define BUTTON1_NODE		DT_NODELABEL(button1)
#define GYRO_INT_NODE		DT_NODELABEL(gyroint)

extern const struct gpio_dt_spec led;
extern const struct gpio_dt_spec button0;
extern const struct gpio_dt_spec button1;

uint8_t gpio_init(void);
void thread_photo(void);

#endif // GPIO_INCLUDED
