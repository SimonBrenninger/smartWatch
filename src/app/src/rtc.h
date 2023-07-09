/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef RTC_INCLUDED
#define RTC_INCLUDED

#include "header.h"
#include <zephyr/drivers/counter.h>

#define TIMER DT_NODELABEL(rtc0)

#define DELAY 1000000
#define ALARM_CHANNEL_ID 0

int rtc_init(const struct device *counter_dev);
void rtc_thread(void *, void *, void *);

#endif // RTC_INCLUDED