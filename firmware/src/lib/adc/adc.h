/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef ADC_INCLUDED
#define ADC_INCLUDED

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <inttypes.h>
#include "../lib.h"

#define ADC_NODE		DT_NODELABEL(adc)

#define ADC_RESOLUTION	8
#define ADC_CHANNEL		0
#define ADC_PORT		SAADC_CH_PSELP_PSELP_AnalogInput6
#define ADC_REFERENCE		ADC_REF_INTERNAL
#define ADC_GAIN		ADC_GAIN_1_5

extern const struct device *adc_dev;

int adc_init(void);
void adc_test(void);
int photo_get_brightness(uint8_t *brightness);

# endif // ADC_INCLUDED
