#include "header.h"
#include "gpio.h"

const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET(BTN0_NODE, gpios);
const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET(BTN1_NODE, gpios);
const struct gpio_dt_spec gyro_int = GPIO_DT_SPEC_GET(GYRO_INT_NODE, gpios);

uint8_t gpio_init(void)
{
    int ret = 0;
    if (!device_is_ready(led.port)) {
		return ret;
	}
	if (!device_is_ready(button0.port)) {
		return ret;
	}
	if (!device_is_ready(button1.port)) {
		return ret;
	}
	
	// configure led as output
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
	if (ret < 0)
	{
		return ret;
	}

	// configure btn0 as input
	ret = gpio_pin_configure_dt(&button0, GPIO_INPUT);
	if (ret < 0)
	{
		return ret;
	}
	// configure btn1 as input
	ret = gpio_pin_configure_dt(&button1, GPIO_INPUT);
	if (ret < 0)
	{
		return ret;
	}
    return 1;
}