#include "header.h"

LOG_MODULE_REGISTER(SmartWatchDemo, LOG_LEVEL);

// K_THREAD_DEFINE(thread_photo_id, 4096, thread_photo, NULL, NULL, NULL, 15, 0, 0);

struct k_timer my_timer;

void my_expiry_function(struct k_timer *timer_id)
{
	gpio_pin_toggle_dt(&led);
}

void toggle_led(void)
{
	//k_thread_suspend();
}

void timer_test(void)
{
	extern void my_expiry_function(struct k_timer *timer_id);
	k_timer_init(&my_timer, my_expiry_function, NULL);
	k_timer_start(&my_timer, K_MSEC(500), K_MSEC(500));
}

void main(void)
{
	int ret;
	LOG_DBG("SmartWatch demo project");

	ret = gpio_init();
	if(ret) { return; } // ret != 0
	pca9957_test();
	
	// mxc400_test();
	//timer_test();

	/* thread creation */
	// LSE clock / time handling
	// phototransistor
	// battery sense
	// status led
	// led driver (mutex for spi)
	// accelerometer (mutex for i2c)
	/* ISRs */
	// button 0, 1
	// accel intr



	//struct k_thread_t led_thread;
	//struct k_thread_stack_t led_thread_stack = K_THREAD_STACK_DEFINE("led_thread", 4096);
	//led_tid = k_thread_create(&led_thread, K_THREAD_STACK_DEFINE("led_thread", 4096), 4096, toggle_led, NULL, NULL, NULL, 5, NULL, K_NO_WAIT);

	while(1) {
		k_msleep(100);
	}
}