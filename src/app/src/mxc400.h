/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#ifndef MX400_INCLUDED
#define MX400_INCLUDED

#include "header.h"
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/gpio.h>

#define I2C_NODE            DT_NODELABEL(i2c0)
#define MXC400_ADDRESS      0x15

// register definition

#define MXC400_INT_SRC0         0x00
#define MXC400_INT_SRC1         0x01
#define MXC400_STATUS           0x02
#define MXC400_XOUT_UPPER       0x03
#define MXC400_XOUT_LOWER       0x04
#define MXC400_YOUT_UPPER       0x05
#define MXC400_YOUT_LOWER       0x06
#define MXC400_ZOUT_UPPER       0x07
#define MXC400_ZOUT_LOWER       0x08
#define MXC400_TOUT             0x09
#define MXC400_INT_MASK0        0x0A
#define MXC400_INT_MASK1        0x0B
#define MXC400_DETECTION        0x0C
#define MXC400_CONTROL          0x0D
#define MXC400_DEVICE_ID        0x0E
#define MXC400_WHO_AM_I         0x0F

// bit definition

// register INT SRC0 bit definitions
#define MXC400_INT_SRC0_SHXP    BIT(0)
#define MXC400_INT_SRC0_SHXM    BIT(1)
#define MXC400_INT_SRC0_SHYP    BIT(2)
#define MXC400_INT_SRC0_SHYM    BIT(3)
#define MXC400_INT_SRC0_CHORXY  BIT(6)
#define MXC400_INT_SRC0_CHORZ   BIT(7)

// register INT SRC1 bit definitions
#define MXC400_INT_SRC1_DRDY    BIT(0)
#define MXC400_INT_SRC1_ORXY0   BIT(4)
#define MXC400_INT_SRC1_ORXY1   BIT(5)
#define MXC400_INT_SRC1_ORZ     BIT(6)
#define MXC400_INT_SRC1_TILT    BIT(7)

#define MXC400_INT_SRC1_SW_RST  BIT(4)

// register STATUS bit definitions
#define MXC400_STATUS_ORIXY0    BIT(0)
#define MXC400_STATUS_ORIXY1    BIT(1)
#define MXC400_STATUS_ORIZ0     BIT(2)
#define MXC400_STATUS_ORIZ1     BIT(3)
#define MXC400_STATUS_ORD       BIT(4)

// register XOUT_UPPER bit definitions
#define MXC400_XOUT_UPPER_11_4

// register XOUT_LOWER bit definitions
#define MXC400_XOUT_LOWER_11_4

// register YOUT_UPPER bit definitions
#define MXC400_YOUT_UPPER_11_4

// register YOUT_LOWER bit definitions
#define MXC400_YOUT_LOWER_11_4

// register ZOUT_UPPER bit definitions
#define MXC400_ZOUT_UPPER_11_4

// register ZOUT_LOWER bit definitions
#define MXC400_ZOUT_LOWER_11_4

// register TOUT bit definitions
// register INT_MASK0 bit definitions
// register INT_MASK1 bit definitions
// register DETECTION bit definitions
// register CONTROL bit definitions

// interrupt flags

#define MXC400_INTFLAG_SHXP     (1 << 0)
#define MXC400_INTFLAG_SHXM     (1 << 1)
#define MXC400_INTFLAG_SHYP     (1 << 2)
#define MXC400_INTFLAG_SHYM     (1 << 3)
#define MXC400_INTFLAG_CHORXY   (1 << 6)
#define MXC400_INTFLAG_CHORZ    (1 << 7)
#define MXC400_INTFLAG_DRDY     (1 << 8)

extern const struct gpio_dt_spec mxc400_int;
extern const struct device *i2c_dev;

int mxc400_init(void);
void mxc400_thread(void *, void *, void *);

#endif // MX400_INCLUDED