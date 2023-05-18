/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
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
#include "gpio.h"
#include "mxc400.h"
#include "pca9957.h"
#include "pca9957_wrapper.h"

#define LOG_LEVEL	            LOG_LEVEL_DBG

#define ERR_DEVICE_NOT_READY      BIT(1)

#endif // HEADER_INCLUDED