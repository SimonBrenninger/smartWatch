/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef ADC_INCLUDED
#define ADC_INCLUDED

#include "header.h"
#include <zephyr/drivers/adc.h>

#define ADC_NODE		DT_NODELABEL(adc)

#define ADC_RESOLUTION	10
#define ADC_CHANNEL		0
#define ADC_PORT		SAADC_CH_PSELP_PSELP_AnalogInput6
#define ADC_REFERENCE	ADC_REF_INTERNAL
#define ADC_GAIN		ADC_GAIN_1_5

extern const struct device *adc_dev;

# endif // ADC_INCLUDED