/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/kernel/thread.h>
#include <zephyr/logging/log.h>
#include <string.h>

#include "../lib.h"

#define NUM_TIMER_CHANNELS	3
#define SEC_IN_US(x)		(x * 1000000UL)

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

static struct k_sem *sems[NUM_TIMER_CHANNELS];
static const struct device *const counter_dev = DEVICE_DT_GET(TIMER);

static void timer_cb(const struct device *counter_dev, uint8_t chan_id, uint32_t ticks, void *sem)
{
	k_sem_give(sem);
	// async notify thread with thread_id; NO_WAIT
	printk("from isr giving sem: %p\n", &sem);
}

int timer_init(struct k_sem *sem, uint64_t time_us)
{
	static int channel_idx = 0;
	struct counter_alarm_cfg cfg;
	memset(&cfg, 0, sizeof(cfg));
	if (counter_dev == NULL || channel_idx == NUM_TIMER_CHANNELS)
	{
		return RETURN_FAILURE;
	}
	sems[channel_idx] = sem;
	if (!device_is_ready(counter_dev) || counter_start(counter_dev) < 0)
	{
		return RETURN_FAILURE;
	}
	cfg.flags = 0;
	cfg.ticks = counter_us_to_ticks(counter_dev, time_us);
	cfg.callback = timer_cb;
	cfg.user_data = sem;
	channel_idx++;
	return RETURN_SUCCESS;
}

/**
 * configure timer to notify thread after time_ms milliseconds.
 *
 */
int config_timer0(uint64_t time_us, k_tid_t thread_id)
{
	// return config_timer();
	return 0;
}
