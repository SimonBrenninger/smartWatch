/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#ifndef RTC_INCLUDED
#define RTC_INCLUDED

#include "../lib.h"
#include <zephyr/drivers/counter.h>
#include <zephyr/kernel/thread.h>
#include <time.h>

#define TIMER DT_NODELABEL(rtc0)

#define DELAY 1000000
#define ALARM_CHANNEL_ID 0

extern struct k_fifo pca_task_fifo;

int rtc_init(const struct device *counter_dev);
void rtc_thread(void *, void *, void *);

void rtc_get_time(struct tm *current_time);
void rtc_set_time(struct tm *current_time);
int timer_init(struct k_sem *sem, uint64_t time_us);

int config_timer(uint64_t time_us, k_tid_t thread_id);

#endif // RTC_INCLUDED
