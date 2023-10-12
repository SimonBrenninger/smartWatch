/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef LIB_INCLUDED
#define LIB_INCLUDED


#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys_clock.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#include "adc/adc.h"
#include "gpio/gpio.h"
#include "rtc/rtc.h"
#include "mxc400/mxc400.h"
#include "pca9957/pca9957.h"
#include "pca9957/pca9957_wrapper.h"

#define LOG_LEVEL	            LOG_LEVEL_DBG

#define ERR_DEVICE_NOT_READY    BIT(1)

#define THREAD_STACK_SIZE       1024

extern k_tid_t pca9957_tid;
extern k_tid_t mxc400_tid;
extern k_tid_t adc_tid;
extern k_tid_t rtc_tid;

#endif // LIB_INCLUDED