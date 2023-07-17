/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef PCA9957_INCLUDED
#define PCA9957_INCLUDED

#include "header.h"
#include <zephyr/drivers/spi.h>

#define SPI_NODE        DT_NODELABEL(spi0)

extern const struct device *pca9957_dev;

// hardware defined offset
// (0 o'clock leds not routed to LED(0) & LED(1))
#define HOUR(n)         PCA9957_LED(2*(n + 10))
#define MINUTE(n)       PCA9957_LED((2*(n + 10) + 1))

#define PCA_TASK_CLOCK      BIT(0)
#define PCA_TASK_LOADING    BIT(1)

int pca9957_init(void);
void pca9957_thread(void *, void *, void *);
int pca9957_loading_demo(uint8_t brightness, uint8_t num_cycles, uint16_t delay_ms);
void pca9957_clock_demo(uint8_t brightness, struct tm *time);

#endif // PCA9957_INCLUDED