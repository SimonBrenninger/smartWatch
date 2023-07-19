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

static struct gpio_callback callback_data;

static uint8_t int_detected = 0;

void mxc400_callback(const struct device *dev, struct gpio_callback *cb, uint32_t pins) {
	//int_detected = 1;
	k_thread_resume(mxc400_tid);
}

/**
 * @brief mxc400 accelerometer thread
 */
void mxc400_thread(void *, void *, void *)
{
	int ret;
	LOG_DBG("MXC400 thread started");
	ret = mxc400_init();

	if(ret)
	{
		LOG_ERR("Error initializing MXC400");
		return;
	}
	LOG_DBG("MXC400 initialized");

	while(1)
	{
		//if(int_detected == 1)
		{
			k_sleep(K_FOREVER);
			gpio_pin_toggle_dt(&led);
			mxc400_interrupt_clear(MXC400_INTFLAG_CHORXY);
			printk("isr cleared\n");
			int_detected = 0;
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
 * @brief initialize mxc400 accelerometer.
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int mxc400_init(void)
{
	int ret;

	if (!device_is_ready(mxc400_int.port) ||
		!device_is_ready(i2c_dev)) {
		return -1;
	}
	
	ret  = gpio_pin_configure_dt(&mxc400_int, GPIO_INPUT);
	
	ret |= gpio_pin_interrupt_configure_dt(&mxc400_int, GPIO_INT_EDGE_FALLING);
	gpio_init_callback(&callback_data, mxc400_callback, BIT(mxc400_int.pin));
	ret |= gpio_add_callback(mxc400_int.port, &callback_data);
	

	ret |= mxc400_interrupt_enable(MXC400_INTFLAG_CHORXY);
	return ret;
}

int mxc400_interrupt_enable(uint16_t intr_flags) {
	int ret;
	uint8_t buf[2];
	buf[0] = MXC400_INT_MASK0;
	buf[1] = (uint8_t) intr_flags;
	ret = i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);

	buf[1] = (uint8_t) (intr_flags >> 8);
	if(buf[1]) {
		buf[0] = MXC400_INT_MASK1;
		ret |= i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);
	}
	return ret;
}

int mxc400_interrupt_clear(uint16_t intr_flags) {
	int ret;
	uint8_t buf[2];
	buf[0] = MXC400_INT_SRC0;
	buf[1] = (uint8_t) intr_flags;
	ret = i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);

	buf[1] = (uint8_t) (intr_flags >> 8);
	if(buf[1]) {
		buf[0] = MXC400_INT_SRC1;
		ret |= i2c_write(i2c_dev, buf, 2, MXC400_ADDRESS);
	}
	return ret;
}

int mxc400_interrupt_pending(uint16_t *intr_flags) {
	int ret;
	uint8_t buf[4];
	struct i2c_msg msgs[4];
	buf[0] = MXC400_INT_SRC0;
	buf[2] = MXC400_INT_SRC1;

	msgs[0].buf = &buf[0];
	msgs[0].len = 1;
	msgs[0].flags = I2C_MSG_WRITE;

	msgs[0].buf = &buf[1];
	msgs[0].len = 1;
	msgs[0].flags = I2C_MSG_READ;

	msgs[1].buf = &buf[2];
	msgs[1].len = 1;
	msgs[1].flags = I2C_MSG_WRITE;

	msgs[1].buf = &buf[3];
	msgs[1].len = 1;
	msgs[1].flags = I2C_MSG_READ;

	ret = i2c_transfer(i2c_dev, msgs, 4, MXC400_ADDRESS);
	*intr_flags = (buf[3] << 8) & buf[1];
	return ret;
}