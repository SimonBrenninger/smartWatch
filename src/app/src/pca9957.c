/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

const struct device *pca9957_dev = DEVICE_DT_GET(SPI_NODE);
volatile uint8_t pca9957_rdy = 0;

static k_tid_t pca9957_delay_tid;
static struct k_thread pca9957_delay_thread_data;

K_THREAD_STACK_DEFINE(pca9957_delay_stack, THREAD_STACK_SIZE);

/**
 * @brief pca9957 led driver thread
 */
void pca9957_delay_thread(void *, void *, void *) {
	volatile uint8_t i = 0;
	while(1) {
		i++;
		k_msleep(1000);
	}
}

static void pca9957_init_delay_thread(void) {
	pca9957_delay_tid = k_thread_create(&pca9957_delay_thread_data,
								pca9957_delay_stack,
								K_THREAD_STACK_SIZEOF(pca9957_delay_stack),
								pca9957_delay_thread, NULL, NULL, NULL,
								  8, 0, K_NO_WAIT);
}


/**
 * @brief pca9957 led driver thread
 */
void pca9957_thread(void *, void *, void *)
{
	int ret;
	uint8_t brightness;
	struct tm time;
	struct pca_task_el *el;

	LOG_DBG("PCA9957 thread started");

	ret = pca9957_init();
	if(ret) {
		LOG_ERR("Error initializing PCA9957");
		return;
	}

	pca9957_init_delay_thread(); // void value not ignored as it ought to be

	pca9957_rdy = 1;
	LOG_DBG("PCA8857 initialized");

	//pca9957_loading_demo(0x05, 1, 30);

	while(1) {
		// wait for notification
		el = k_fifo_get(&pca_task_fifo, K_FOREVER);
		photo_get_brightness(&brightness);
		switch (el->task) {
			case PCA9957_TASK_CLOCK:
			{
				rtc_get_time(&time);
				pca9957_clock_demo(brightness, &time);
				pca9957_update_brightness(PCA9957_CLOCK_DELAY_MS,
										  PCA9957_CLOCK_UPDATE_MS);
				pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
				break;
			}
			case PCA9957_TASK_LOADING:
			{
				pca9957_loading_demo(brightness, 1, 30);
				break;
			}
			case PCA9957_TASK_OFF:
			{
				pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
				break;
			}
			default:
				break;
		}
		// tell mxc400_thread pca9957 is ready
		k_thread_resume(mxc400_tid);
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
	int ret;
	if(!device_is_ready(pca9957_dev)) {
		return ERR_DEVICE_NOT_READY;
	}
	// set current, pwm, led-mode
	ret = pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
	if (ret) { return ret; }
	ret = pca9957_set_led_current(PCA9957_LEDS_MSK, 0x01);
	if (ret) { return ret; }
	ret = pca9957_set_led_pwm(PCA9957_LEDS_MSK, 0x05);
	return ret;
}

void pca9957_update_brightness(uint32_t duration_ms, uint8_t intervall_ms) {
	uint32_t i = 0;
	uint8_t brightness;

	while(i < (duration_ms / intervall_ms)) {
		photo_get_brightness(&brightness);
		pca9957_set_led_pwm(PCA9957_LEDS_MSK, brightness);
		k_msleep(intervall_ms);
		i++;
	}
}

void pca9957_clock_demo(uint8_t brightness, struct tm *time)
{
	int ret = 0;
	ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
	ret |= pca9957_set_led_pwm(PCA9957_LEDS_MSK, brightness);

	ret |= pca9957_set_led_mode(HOUR(time->tm_hour) | MINUTE(time->tm_min), PCA9957_LEDMODE_PWM);
	
}

/**
 * @brief loading demo executed the specified number of cycles
 * 
 * @param brightness brightness of active led (0x00 off, 0xFF fully on)
 * @param num_cycles number of cycles to execute
 * @param delay number of milliseconds to wait after each iteration
 * 			with delay * PCA9957_NUM_LEDS being a rough estimate of
 * 			 the elapsed after a full cycle
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 * 
 * @note the calling thread will be blocked during execution
 */
int pca9957_loading_demo(uint8_t brightness, uint8_t num_cycles, uint16_t delay_ms)
{
	int ret, h, m;
	m = 12;
	h = 0;

	ret = pca9957_set_led_current(PCA9957_LEDS_MSK, 0x01);
	
	while(num_cycles > 0) {
		ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
		ret |= pca9957_set_led_pwm(PCA9957_LEDS_MSK, 0x05);

		ret |= pca9957_set_led_pwm(LED_INNER(h) | LED_OUTER(m), 0x50);
		ret |= pca9957_set_led_pwm(LED_INNER(h-1) | LED_INNER(h+1) | LED_OUTER(m-1) | LED_OUTER(m+1), 0x02);
		ret |= pca9957_set_led_mode(LED_INNER(h) | LED_OUTER(m), PCA9957_LEDMODE_PWM);
		ret |= pca9957_set_led_mode(LED_INNER(h-1) | LED_INNER(h+1) | LED_OUTER(m-1) | LED_OUTER(m+1), PCA9957_LEDMODE_PWM);
		h++;
		m--;
		if(h == 12) {
			m = 12;
			h = 0;
			num_cycles--;
		}
		if(ret) {
			LOG_ERR("Error occured writing to PCA9957");
			return ret;
		}
		k_msleep(delay_ms);
	}

	ret |= pca9957_set_led_pwm(PCA9957_LEDS_MSK, 0x00);
	ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);
	return ret;
}