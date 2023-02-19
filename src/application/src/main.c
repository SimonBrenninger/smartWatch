#include "header.h"
#include "gpio.h"
#include "pca9957.h"

LOG_MODULE_REGISTER(SmartWatchDemo, DEMO_LOG_LEVEL);

static const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);

void i2c_test(void)
{
	int ret;
	uint8_t buf;

	if (!device_is_ready(gyro_int.port)) {
		gpio_pin_set_dt(&led, 1);
		return;
	}
	// configure gyro_int as input
	ret = gpio_pin_configure_dt(&gyro_int, GPIO_INPUT);
	if (ret < 0)
	{
		gpio_pin_set_dt(&led, 1);
		return;
	}

	if (!device_is_ready(i2c_dev)) {
		LOG_ERR("I2C not ready!\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}
	buf = 0x0E;
	ret = i2c_write(i2c_dev, &buf, 1, I2C_ADDRESS);
	if(ret != 0) {
		LOG_ERR("Error writing to I2C device\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	ret = i2c_read(i2c_dev, &buf, 1, I2C_ADDRESS);
	if(ret != 0) {
		LOG_ERR("Error reading from I2C device\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	if(buf != 0x02)
	{
		gpio_pin_set_dt(&led, 1);
		return;
	}

	while(1)
	{
		if(gpio_pin_get_dt(&button0))
		{
			gpio_pin_toggle_dt(&led);
		}
		//gpio_pin_set_dt(&led, gpio_pin_get_dt(&gyro_int));
		k_msleep(100);
	}

}

void main(void)
{
	int ret;
	LOG_DBG("SmartWatch demo project");

	ret = gpio_init();
	if(!ret)
		return;

	spi_test();
	
	return;
}