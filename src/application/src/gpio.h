#ifndef HEADER_GPIO_INCLUDED
#define HEADER_GPIO_INCLUDED

#include "header.h"
#include <zephyr/drivers/gpio.h>

#define LED0_NODE		DT_ALIAS(led0)
#define BTN0_NODE		DT_ALIAS(btn0)
#define BTN1_NODE		DT_ALIAS(btn1)
#define GYRO_INT_NODE	DT_ALIAS(mxc400_int)

extern const struct gpio_dt_spec led;
extern const struct gpio_dt_spec button0;
extern const struct gpio_dt_spec button1;

uint8_t gpio_init(void);

#endif // HEADER_GPIO_INCLUDED