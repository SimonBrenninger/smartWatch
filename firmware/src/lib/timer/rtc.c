/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

#include "../lib.h"

#define SEC_IN_US(x)		(x * 1000000UL)

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

static struct k_sem sem;
static struct tm rtc_time;
static struct counter_alarm_cfg time_cfg;

static void counter_callback(const struct device *counter_dev, uint8_t chan_id,
 							 uint32_t ticks, void *user_data);


int rtc_init(const struct device *counter_dev)
{
	int ret = 0;

	k_sem_init(&sem, 0, 3);
	if (timer_init(&sem, SEC_IN_US(1)) == RETURN_FAILURE)
	{
		return RETURN_FAILURE;
	}

	rtc_time.tm_hour = 3;
	rtc_time.tm_min = 45;
	rtc_time.tm_sec = 0;

	return RETURN_SUCCESS;

	memset(&time_cfg, 0, sizeof(time_cfg));

	time_cfg.flags = 0;
	time_cfg.ticks = counter_us_to_ticks(counter_dev, DELAY);
	time_cfg.callback = counter_callback;
	time_cfg.user_data = &time_cfg;

	ret = counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID, &time_cfg);
	// take sem
	// increment time
	return ret;
}

static void counter_callback(const struct device *counter_dev, uint8_t chan_id,
 							 uint32_t ticks, void *user_data)
{
	counter_set_channel_alarm(counter_dev, ALARM_CHANNEL_ID, &time_cfg);

	if (++rtc_time.tm_sec == 60) {
		rtc_time.tm_sec = 0;
		if (++rtc_time.tm_min == 60) {
			rtc_time.tm_min = 0;
			if (++rtc_time.tm_hour == 60) {
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

	if (err)
	{
		LOG_ERR("Error initializing RTC");
		return;
	}

	LOG_DBG("RTC initialized");

	while(1)
	{
		k_sem_take(&sem, K_FOREVER);
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
}

void rtc_get_time(struct tm *current_time)
{
	*current_time = rtc_time;
}

void rtc_set_time(struct tm *current_time)
{
	rtc_time = *current_time;
}
