/*
 * Copyright (c) 2025 Simon Brenninger
 * SPDX-License-Identifier: GPLv3
 */

#ifndef LIB_INCLUDED
#define LIB_INCLUDED

#include <zephyr/kernel.h>
#include <zephyr/kernel/thread.h>
#include <zephyr/logging/log.h>
#include "adc/adc.h"
#include "gpio/gpio.h"
#include "timer/timer.h"
#include "mxc400/mxc400.h"
#include "pca9957/pca9957.h"
#include "pca9957/pca9957_wrapper.h"

#define LOG_LEVEL	            LOG_LEVEL_DBG

#define RETURN_SUCCESS		0
#define RETURN_FAILURE		-1

#define THREAD_STACK_SIZE       1024

extern k_tid_t pca9957_tid;
extern k_tid_t mxc400_tid;
extern k_tid_t adc_tid;
extern k_tid_t rtc_tid;

#endif // LIB_INCLUDED
