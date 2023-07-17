/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"

LOG_MODULE_REGISTER(SmartWatchDemo, LOG_LEVEL);

K_THREAD_STACK_DEFINE(pca9957_stack, THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(mxc400c_stack, THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(rtc_stack, THREAD_STACK_SIZE);

k_tid_t pca9957_tid;
k_tid_t mxc400_tid;
k_tid_t adc_tid;
k_tid_t rtc_tid;

struct k_thread pca9957_thread_data;
struct k_thread mxc400_thread_data;
struct k_thread rtc_thread_data;


/**
 * @brief main thread
 */

void main(void)
{
	int ret;
	LOG_DBG("SmartWatch demo project");

	ret = gpio_init();
	ret |= adc_init();

	if(ret) {
		LOG_ERR("Error initializing periphs");
	} else {
		LOG_DBG("peripherals initialized");
		
		pca9957_tid = k_thread_create(&pca9957_thread_data, pca9957_stack,
									  K_THREAD_STACK_SIZEOF(pca9957_stack),
									  pca9957_thread,
									  NULL, NULL, NULL,
									  7, 0, K_NO_WAIT);
		
		mxc400_tid = k_thread_create(&mxc400_thread_data, mxc400c_stack,
									 K_THREAD_STACK_SIZEOF(mxc400c_stack),
									 mxc400_thread,
									 NULL, NULL, NULL,
									 6, 0, K_NO_WAIT);

		rtc_tid = k_thread_create(&rtc_thread_data, rtc_stack,
								  K_THREAD_STACK_SIZEOF(rtc_stack),
								  rtc_thread,
								  NULL, NULL, NULL,
								  5, 0, K_NO_WAIT);
	}
	return;
}

/* 
 * application structure:
 * reset:
 * init peripherals
 * create threads:
 * - pca9957 thread:
 * 		init led driver
 * 		suspend and wait for notifications
 * 		when notified:
 * 			get brightness level
 * 			perform notified task
 * 			suspend
 * - mxc400 thread:
 * 		init interrupt callback
 * 		return
 * 		- callback:
 * 			reset pending interrupt flags
 * 			notify led driver to perform task
 * 			return
 * - rtc thread:
 * 		init rtc
 * 		init time
 * 		add timer callback (every sec)
 * 		return
 * 		callback:
 * 			update time
 * 			return
 *
 */