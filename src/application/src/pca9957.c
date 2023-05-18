#include "header.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

const struct device *pca9957_dev = DEVICE_DT_GET(SPI_NODE);

/**
 * @brief initializes PCA9957 spi led driver.
 * 	sets all led channels to inactive
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

int pca9957_test(void)
{
	int m, h, ret;

	ret = pca9957_init();

	m = 12;
	h = 0;
	while(!ret) {
		ret |= pca9957_set_led_mode(PCA9957_LEDS_MSK, PCA9957_LEDMODE_OFF);

		ret |= pca9957_set_led_pwm(HOUR(h) | MINUTE(m), 0x50);
		ret |= pca9957_set_led_pwm(HOUR(h-1) | HOUR(h+1) | MINUTE(m-1) | MINUTE(m+1), 0x02);
		ret |= pca9957_set_led_mode(HOUR(h) | MINUTE(m), PCA9957_LEDMODE_PWM);
		ret |= pca9957_set_led_mode(HOUR(h-1) | HOUR(h+1) | MINUTE(m-1) | MINUTE(m+1), PCA9957_LEDMODE_PWM);
		h++;
		m--;
		if(h == PCA9957_NUM_LEDS/2) {
			m = 12;
			h = 0;
		}
		k_msleep(100);
	}

	return ret;
}