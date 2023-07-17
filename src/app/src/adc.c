/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"
#include "adc.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

// adc definitions

const struct device *adc_dev = DEVICE_DT_GET(ADC_NODE);

int16_t adc_buf; // why not uint8_t ?

const struct adc_channel_cfg adc_cfg = {
	.gain = ADC_GAIN,
	.reference = ADC_REFERENCE,
	.acquisition_time = ADC_ACQ_TIME_DEFAULT,
	.channel_id = ADC_CHANNEL,
#ifdef CONFIG_ADC_NRFX_SAADC
	.input_positive = ADC_PORT
#endif
};

struct adc_sequence sequence = {
	.channels = BIT(ADC_CHANNEL),
	.buffer = &adc_buf,
	.buffer_size = sizeof(adc_buf),
	.resolution = ADC_RESOLUTION
};

int adc_init(void) {
	int ret = 0;
	if(!device_is_ready(adc_dev)) {
		return -1;
	}
	
	ret = adc_channel_setup(adc_dev, &adc_cfg);
	return ret;
}

/**
 * @brief get brightness of the photodiode.
 * 
 * @param brightness measured brightness off photodiode
 * 			0x00: dark, 0xFF bright
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int photo_get_brightness(uint8_t *brightness) {
	int ret = adc_read(adc_dev, &sequence);
	*brightness = (adc_buf < 0) ? 0 : adc_buf;
	return ret;
}

void adc_test(void)
{
	int ret = 0;

	uint8_t pwm;
	int delay;
	while (!ret)
	{
		ret = photo_get_brightness(&pwm);
		if(ret) {
			LOG_ERR("failed reading ADC!\n");
			gpio_pin_set_dt(&led, 1);
			return;
		}
		delay = pwm*4; // 0...1000
		printk("%d\t%d\n", pwm, delay);

		gpio_pin_set_dt(&led, 1);
		k_usleep(delay);
		gpio_pin_set_dt(&led, 0);
		k_usleep(1000 - delay);
	}
}