#include "header.h"

LOG_MODULE_REGISTER(SmartWatchDemo, LOG_LEVEL);

void main(void)
{
	int ret;
	LOG_DBG("SmartWatch demo project");

	ret = gpio_init();
	if(!ret)
		return;

	// pca9957_test();
	mxc400_test();
	
	return;
}