/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "header.h"
#include "mxc400.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);
const struct gpio_dt_spec mxc400_int = GPIO_DT_SPEC_GET(GYRO_INT_NODE, gpios);

/**
 * @brief mxc400 accelerometer thread
 */
void mxc400_thread(void *, void *, void *)
{
	int ret;
	uint8_t buf[2];

	LOG_DBG("MXC400 thread started");

	ret = mxc400_init();

	if(ret)
	{
		LOG_ERR("Error initializing MXC400");
		return;
	}

	LOG_DBG("MXC400 initialized");

	// interface with register 0x0A
	buf[0] = 0x0A;
	// set SHXPE (shake x+ enable) bit
	buf[1] = 0x0F;
	ret = i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);
	if(ret != 0)
	{
		LOG_ERR("Error writing to I2C device\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	while(1)
	{
		if(gpio_pin_get_dt(&mxc400_int) == 1)
		{
			//gpio_pin_toggle_dt(&led);

			// interrupt pin state reflects
			// state of INT bit in STATUS reg
			// clear by setting INT_CLRx
			
			// interface with register 0x00
			buf[0] = 0x00;
			// set SHXP (shake x+ enable) bit
			buf[1] = 0x0F;
			ret = i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);
			if(ret != 0)
			{
				LOG_ERR("Error clearing I2C interrupt\n");
				gpio_pin_set_dt(&led, 1);
				return;
			}
			LOG_DBG("shake detected");
		}
		k_msleep(100);
	}

}

/*
reading device ID:

buf = 0x0E;
	ret = i2c_write(i2c_dev, &buf, 1, I2C_ADDRESS);
	if(ret != 0)
	{
		LOG_ERR("Error writing to I2C device\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	ret = i2c_read(i2c_dev, &buf, 1, I2C_ADDRESS);
	if(ret != 0)
	{
		LOG_ERR("Error reading from I2C device\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	if(buf != 0x02)
	{
		gpio_pin_set_dt(&led, 1);
		return;
	}

*/

/**
 * @brief initialize PCA9957 spi led driver.
 * sets all led channels inactive
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int mxc400_init(void)
{
	int ret;
	if (!device_is_ready(mxc400_int.port) || !device_is_ready(i2c_dev)) {
		gpio_pin_set_dt(&led, 1);
		return -1;
	}
	// configure mxc400_int as input
	ret = gpio_pin_configure_dt(&mxc400_int, GPIO_INPUT);
	if (ret < 0)
	{
		gpio_pin_set_dt(&led, 1);
	}
	return ret;
}