/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

struct counter_alarm_cfg alarm_cfg;

int rtc_init(const struct device *counter_dev) {
	int ret = 0;
    if (!device_is_ready(counter_dev)) {
		ret = -1;
	}
	return ret;
}

static void test_counter_interrupt_fn(const struct device *counter_dev,
				      uint8_t chan_id, uint32_t ticks,
				      void *user_data)
{
	uint32_t now_ticks;
	uint64_t now_usec;
	int now_sec;
	int err;

	err = counter_get_value(counter_dev, &now_ticks);
	if (err) {
		printk("Failed to read counter value (err %d)", err);
		return;
	}

	now_usec = counter_ticks_to_us(counter_dev, now_ticks);
	now_sec = (int)(now_usec / USEC_PER_SEC);

    gpio_pin_toggle_dt(&led);
	printk("!!! Alarm !!!\n");
	printk("Now: %u\n", now_sec);

    err = counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID,
					user_data);
	if (err != 0) {
		printk("Alarm could not be set\n");
	}
}

/**
 * @brief rtc thread
 */
void rtc_thread(void *, void *, void *)
{
	const struct device *const counter_dev = DEVICE_DT_GET(TIMER);
	int err;

	LOG_DBG("RTC_thread started");

	err = rtc_init(counter_dev);

	if (err) {
		LOG_ERR("Error initializing RTC");
		return;
	}

	LOG_DBG("RTC initialized");

	counter_start(counter_dev);

	alarm_cfg.flags = 0;
	alarm_cfg.ticks = counter_us_to_ticks(counter_dev, DELAY);
	alarm_cfg.callback = test_counter_interrupt_fn;
	alarm_cfg.user_data = &alarm_cfg;

	err = counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID,
					&alarm_cfg);
	printk("Set alarm in %u sec (%u ticks)\n",
	       (uint32_t)(counter_ticks_to_us(counter_dev,
					   alarm_cfg.ticks) / USEC_PER_SEC),
	       alarm_cfg.ticks);

	if (-EINVAL == err) {
		//printk("Alarm settings invalid\n");
	} else if (-ENOTSUP == err) {
		//printk("Alarm setting request not supported\n");
	} else if (err != 0) {
		//printk("Error\n");
	}

	while (1) {
		k_sleep(K_FOREVER);
	}
}
