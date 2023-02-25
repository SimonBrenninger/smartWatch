#include "header.h"
#include "adc.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

// adc definitions

const struct device *adc_dev = DEVICE_DT_GET(ADC_NODE);

int16_t adc_buf;

const struct adc_channel_cfg adc_cfg = {
	.gain = ADC_GAIN,
	.reference = ADC_REFERENCE,
	.acquisition_time = ADC_ACQ_TIME_DEFAULT,
	.channel_id = ADC_CHANNEL,
#ifdef CONFIG_ADC_NRFX_SAADC
	.input_positive = ADC_PORT
#endif
};

struct adc_sequence sequence = {
	.channels = BIT(ADC_CHANNEL),
	.buffer = &adc_buf,
	.buffer_size = sizeof(adc_buf),
	.resolution = ADC_RESOLUTION
};

void adc_test(void)
{
	int ret;
	if(!device_is_ready(adc_dev))
	{
		gpio_pin_set_dt(&led, 1);
		return;
	}
	
	ret = adc_channel_setup(adc_dev, &adc_cfg);
	if(ret != 0) {
		LOG_ERR("ADC not ready!\n");
		gpio_pin_set_dt(&led, 1);
		return;
	}

	while (1)
	{
		uint8_t pwm = 0;
		ret = adc_read(adc_dev, &sequence);
		if(ret) {
			LOG_ERR("failed reading ADC!\n");
			gpio_pin_set_dt(&led, 1);
			return;
		}
		// 10bit -> 8bit
		pwm = (adc_buf * 20) / 1023;

		gpio_pin_set_dt(&led, 1);
		k_msleep(pwm);
		gpio_pin_set_dt(&led, 0);
		k_msleep(20 - pwm);
	}
}
