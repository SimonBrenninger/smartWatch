/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED


#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys_clock.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

#include "adc.h"
#include "rtc.h"
#include "gpio.h"
#include "mxc400.h"
#include "pca9957.h"
#include "pca9957_wrapper.h"

#define LOG_LEVEL	            LOG_LEVEL_DBG

#define ERR_DEVICE_NOT_READY    BIT(1)

#define THREAD_STACK_SIZE       1024

extern k_tid_t pca9957_tid;
extern k_tid_t mxc400_tid;
extern k_tid_t adc_tid;
extern k_tid_t rtc_tid;

#endif // HEADER_INCLUDED