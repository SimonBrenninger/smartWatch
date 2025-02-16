/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#ifndef PCA9957_INCLUDED
#define PCA9957_INCLUDED

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <stdint.h>
#include <time.h>
#include "../lib.h"

#define SPI_NODE        DT_NODELABEL(spi0)

extern const struct device *pca9957_dev;

// hardware defined offset
// (0 o'clock leds not routed to LED(0) & LED(1))
#define LED_INNER(n)        PCA9957_LED(2*(n + 10))
#define LED_OUTER(n)        PCA9957_LED((2*(n + 10) + 1))

#define HOUR(n)             LED_INNER(n % 12)
#define MINUTE(n)           LED_OUTER((n/5) % 12)

#define PCA9957_TASK_OFF        BIT(0)
#define PCA9957_TASK_CLOCK      BIT(1)
#define PCA9957_TASK_LOADING    BIT(2)

#define PCA9957_CLOCK_DELAY_MS  4000
#define PCA9957_CLOCK_UPDATE_MS 20

struct pca_task_el {
    void *res;
	uint8_t task;
};

extern volatile uint8_t pca_rdy; // use semaphore instead?

int pca9957_init(void);
void pca9957_thread(void *, void *, void *);
int pca9957_loading_demo(uint8_t brightness, uint8_t num_cycles, uint16_t delay_ms);
void pca9957_clock_demo(uint8_t brightness, struct tm *time);
void pca9957_update_brightness(uint32_t duration_ms, uint8_t intervall_ms);

#endif // PCA9957_INCLUDED
