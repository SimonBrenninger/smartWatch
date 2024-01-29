/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef RTC_INCLUDED
#define RTC_INCLUDED

#include "../lib.h"
#include <zephyr/drivers/counter.h>
#include <time.h>

#define TIMER DT_NODELABEL(rtc0)

#define DELAY 1000000
#define ALARM_CHANNEL_ID 0

extern struct k_fifo pca_task_fifo;

int rtc_init(const struct device *counter_dev);
void rtc_thread(void *, void *, void *);

void rtc_get_time(struct tm *current_time);
void rtc_set_time(struct tm *current_time);

#endif // RTC_INCLUDED