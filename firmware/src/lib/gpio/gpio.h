/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef GPIO_INCLUDED
#define GPIO_INCLUDED

#include "../lib.h"
#include <zephyr/drivers/gpio.h>

#define LED0_NODE		DT_NODELABEL(led0)
#define BTN0_NODE		DT_NODELABEL(btn0)
#define BTN1_NODE		DT_NODELABEL(btn1)
#define GYRO_INT_NODE	DT_NODELABEL(gyroint)

extern const struct gpio_dt_spec led;
extern const struct gpio_dt_spec button0;
extern const struct gpio_dt_spec button1;

uint8_t gpio_init(void);
void thread_photo(void);

#endif // GPIO_INCLUDED