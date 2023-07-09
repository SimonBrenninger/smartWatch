/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

const struct device *pca9957_dev = DEVICE_DT_GET(SPI_NODE);

/**
 * @brief pca9957 led driver thread
 */
void pca9957_thread(void *, void *, void *)
{
	int ret;

	LOG_DBG("PCA9957 thread started");

	ret = pca9957_init();

	if(ret) {
		LOG_ERR("Error initializing PCA9957");
		return;
	}

	LOG_DBG("PCA8857 initialized");

	while(1) {
		// do something
	}
}

/**
 * @brief initialize PCA9957 spi led driver.
 * sets all led channels inactive
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_init() {
	int ret = 0;
	if(!device_is_ready(pca9957_dev)) {
		return ERR_DEVICE_NOT_READY;
	}
	// set current, pwm, led-mode
	ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
	ret |= pca9957_set_led_current(PCA9957_LEDS_MSK, 0x01);
	ret |= pca9957_set_led_pwm(PCA9957_LEDS_MSK, 0x05);
	return ret;
}

void pca9957_clock_demo(void)
{
	
}

/**
 * @brief loading demo executed the specified number of cycles
 * 
 * @param num_cycles number of cycles to execute
 * @param delay number of milliseconds to wait after each iteration
 * 			with delay * PCA9957_NUM_LEDS being a rough estimate of
 * 			time elapsed after a full cycle
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 * 
 * @note the calling thread will be blocked during execution
 */
int pca9957_loading_demo(uint8_t num_cycles, uint16_t delay)
{
	int ret, h, m;
	m = 12;
	h = 0;
	while(num_cycles > 0) {
		ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
		ret |= pca9957_set_led_current(PCA9957_LEDS_MSK, 0x01);
		ret |= pca9957_set_led_pwm(PCA9957_LEDS_MSK, 0x05);

		ret |= pca9957_set_led_pwm(HOUR(h) | MINUTE(m), 0x50);
		ret |= pca9957_set_led_pwm(HOUR(h-1) | HOUR(h+1) | MINUTE(m-1) | MINUTE(m+1), 0x02);
		ret |= pca9957_set_led_mode(HOUR(h) | MINUTE(m), PCA9957_LEDMODE_PWM);
		ret |= pca9957_set_led_mode(HOUR(h-1) | HOUR(h+1) | MINUTE(m-1) | MINUTE(m+1), PCA9957_LEDMODE_PWM);
		h++;
		m--;
		if(h == 12) {
			m = 12;
			h = 0;
		}
		if(ret) {
			LOG_ERR("Error occured writing to PCA9957");
			return ret;
		}
		k_msleep(delay);
		num_cycles--;
	}
	return 0;
}