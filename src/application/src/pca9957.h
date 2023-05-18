#ifndef PCA9957_INCLUDED
#define PCA9957_INCLUDED

#include "header.h"
#include <zephyr/drivers/spi.h>

#define SPI_NODE        DT_NODELABEL(spi0)

extern const struct device *pca9957_dev;

// hardware defined offset
// (0 o'clock leds not routed to LED(0) & LED(1))
#define HOUR(n)         PCA9957_LED(2*(n + 10))
#define MINUTE(n)       PCA9957_LED((2*(n + 10) + 1))

int pca9957_test(void);
int pca9957_init(void);

#endif // PCA9957_INCLUDED