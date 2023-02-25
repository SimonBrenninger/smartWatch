#ifndef HEADER_MX400_INCLUDED
#define HEADER_MX400_INCLUDED

#include "header.h"
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/gpio.h>

#define I2C_NODE        DT_ALIAS(i2c0)
#define I2C_ADDRESS     0x15

extern const struct gpio_dt_spec mxc400_int;

extern const struct device *i2c_dev;

void mxc400_test(void);

#endif // HEADER_MX400_INCLUDED