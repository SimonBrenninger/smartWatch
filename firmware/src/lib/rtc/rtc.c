/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

#include "../lib.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

static void counter_callback(const struct device *counter_dev, uint8_t chan_id,
							 uint32_t ticks, void *user_data);

static struct tm rtc_time;
static struct counter_alarm_cfg alarm_cfg;

int rtc_init(const struct device *counter_dev)
{
	int ret = 0;

	rtc_time.tm_hour = 3;
	rtc_time.tm_min = 45;
	rtc_time.tm_sec = 0;

    if (!device_is_ready(counter_dev)) {
		ret = -1;
	}

	counter_start(counter_dev);

	alarm_cfg.flags = 0;
	alarm_cfg.ticks = counter_us_to_ticks(counter_dev, DELAY);
	alarm_cfg.callback = counter_callback;
	alarm_cfg.user_data = &alarm_cfg;

	ret = counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID, &alarm_cfg);
	return ret;
}

static void counter_callback(const struct device *counter_dev, uint8_t chan_id,
 							 uint32_t ticks, void *user_data)
{
	counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID, &alarm_cfg);

	rtc_time.tm_sec++;
	if (rtc_time.tm_sec == 60) {
		rtc_time.tm_sec = 0;
		rtc_time.tm_min++;
		if (rtc_time.tm_min == 60) {
			rtc_time.tm_min = 0;
			rtc_time.tm_hour++;
			if (rtc_time.tm_hour == 60) {
				rtc_time.tm_hour = 0;
			}
		}
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
}

void rtc_get_time(struct tm *current_time)
{
	*current_time = rtc_time;
}

void rtc_set_time(struct tm *current_time)
{
	rtc_time = *current_time;
}
