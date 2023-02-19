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
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

//#include <zephyr/sys/printk.h>
//#include <errno.h>

#define DEMO_LOG_LEVEL	LOG_LEVEL_DBG

#define LED0_NODE		DT_ALIAS(led0)
#define ADC_NODE		DT_NODELABEL(adc)
#define I2C_NODE        DT_ALIAS(i2c0)
#define SPI_NODE        DT_ALIAS(spi0)


#define BTN0_NODE		DT_ALIAS(btn0)
#define BTN1_NODE		DT_ALIAS(btn1)
#define GYRO_INT_NODE	DT_ALIAS(gyro_int)

#define ADC_RESOLUTION	10
#define ADC_CHANNEL		0
#define ADC_PORT		SAADC_CH_PSELP_PSELP_AnalogInput6
#define ADC_REFERENCE	ADC_REF_INTERNAL
#define ADC_GAIN		ADC_GAIN_1_5

#define I2C_ADDRESS     0x15

extern const struct gpio_dt_spec led;

extern const struct gpio_dt_spec button0;
extern const struct gpio_dt_spec button1;
extern const struct gpio_dt_spec gyro_int;

#endif // HEADER_INCLUDED