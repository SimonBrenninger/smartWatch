#include "pca9957.h"

LOG_MODULE_DECLARE(SmartWatchDemo, LOG_LEVEL);

// SPI struct definitions

static uint8_t my_spi_buf[2];

static struct spi_config config = {
	.frequency = 1000000,
	.operation = SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8),
	.cs = SPI_CS_CONTROL_PTR_DT(DT_NODELABEL(pca9957), 0),
};

static struct spi_buf spi_buffer = {
	.buf = my_spi_buf,
	.len = 2 * sizeof(my_spi_buf[0])
};
static struct spi_buf_set spi_buffers = {
	.buffers = &spi_buffer,
	.count = 1
};

static uint8_t led_mode[PCA9957_NUM_LEDOUT_REGS] = {0};
static uint8_t led_pwm[PCA9957_NUM_LEDS] = {0};

/**
 * @brief set pca9957 low-power mode
 * 
 * @note make sure group dimming/blinking is disabled before entering
 * low-power mode, otherwise the state of the led channels after exiting
 * low-power mode again will result in an undefined behaviour.
 * 
 * @param low_power either PCA9957_LOW_POWER_EN or PCA9957_LOW_POWER_DIS
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_set_power_mode(uint8_t low_power) {
	return pca9957_write(PCA9957_MODE1, low_power << PCA9957_MODE1_SLEEP);
}

/**
 * @brief get pca9957s current low-power mode
 * 
 * @param low_power either PCA9957_LOW_POWER_EN or PCA9957_LOW_POWER_DIS
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_get_power_mode(uint8_t *low_power) {
	int ret = pca9957_read(PCA9957_MODE1, low_power);
	*low_power = *low_power >> PCA9957_MODE1_SLEEP;
	return ret;
}

/**
 * @brief get the content of pca9957 mode2 register
 * 
 * @param status buffer where mode2 register content will be written to
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_get_status(uint8_t *status) {
	return pca9957_read(PCA9957_MODE2, status);
}

/**
 * @brief pca9957 error checker
 * 
 * @param status buffer to write error register content to
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_check_error(uint8_t *error) {
	int ret;
	ret = pca9957_get_status(error);
	*error = *error & (PCA9957_MODE2_OVERTEMP & PCA9957_MODE2_ERROR);
	return ret;
}

/**
 * @brief sets output mode for the chosen led channels
 *
 * @param leds selected LEDs; use PCA9957_LED(n) to choose a selection
 * or PCA9957_LEDS_MSK to select all channels
 * @param mode one of the following: 
 * PCA9957_LEDMODE_OFF: turn led(s) off
 * PCA9957_LEDMODE_ON: turn led(s) fully on
 * PCA9957_LEDMODE_PWM: enable PWM mode
 * PCA9957_LEDMODE_GROUP: enable group dimming/blinking
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 * 
 * @note when selecting either PCA9957_LEDMODE_PWM or PCA9957_LEDMODE_GROUP make
 * sure pca9957_set_led_pwm or pca9957_set_group_mode is configured in advance
 */
int pca9957_set_led_mode(uint32_t leds, uint8_t mode) {
	int i, ret = 0;
	volatile uint8_t mask, new_mode = 0x00;
	i = 0;
	while(i < PCA9957_NUM_LEDS && !ret) {
		if(leds & PCA9957_LED(i))
		{
			// change led i mode
			new_mode |= mode << PCA9957_LEDMODE_POS(i);
		}
		else
		{
			// keep previous mode for led i
			mask = PCA9957_LEDMODE_MSK << PCA9957_LEDMODE_POS(i);
			new_mode |= (led_mode[PCA9957_LEDOUT_REG(i)] & mask);
		}
		if(PCA9957_LEDMODE_POS((i+1)) == 0 && i > 0)
		{
			// write new_mode to pca9957
			ret = pca9957_write(PCA9957_LEDOUT(PCA9957_LEDOUT_REG(i)), new_mode);
			led_mode[PCA9957_LEDOUT_REG(i)] = new_mode;
			new_mode = 0x00;
		}
		i++;
	}
	return ret;
}

/**
 * @brief sets the pwm duty cycle for the chosen led channels
 *
 * @param leds selected LEDs; use PCA9957_LED(n) to choose a selection
 * or PCA9957_LEDS_MSK to select all channels
 * @param pwm 8-bit pwm duty cycle (0x00 - 0xFF)
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_set_led_pwm(uint32_t leds, uint8_t pwm) {
	int i, ret = 0;
	if(leds == PCA9957_LEDS_MSK) {
	return pca9957_write(PCA9957_PWMALL, pwm);
	}
	i = 0;
	while(i < PCA9957_NUM_LEDS && !ret) {
		if(leds & PCA9957_LED(i)) {
			if(led_pwm[i] != pwm) {
				ret |= pca9957_write(PCA9957_PWM(i), pwm);
				led_pwm[i] = pwm;
			}
		}
		i++;
	}
	return ret;
}

/**
 * @brief sets the max output current for each led channels
 *
 * @param leds selected LEDs; use PCA9957_LED(n) to choose a selection
 * or PCA9957_LEDS_MSK to select all channels
 * @param pwm 8-bit current setting (0x00 - 0xFF)
 * 
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_set_led_current(uint32_t leds, uint8_t current) {
	int i, ret = 0;
	if(leds == PCA9957_LEDS_MSK) {
	return pca9957_write(PCA9957_IREFALL, current);
	}
	i = 0;
	while(i < PCA9957_NUM_LEDS && !ret) {
		if(leds & PCA9957_LED(i)) {
			ret |= pca9957_write(PCA9957_IREF(i), current);
		}
		i++;
	}
	return ret;
}

/**
 * @brief writes one byte to the specified register
 * 
 * @param reg 7-bit register address to be written to
 * @param tx_buf buffer where data to be written is stored
 *
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_write(uint8_t reg, uint8_t tx_buf) {
	// ********** SPI WRITING **********
	// send first 7 bit with register address MSB
	// LSB reset to write from device
	my_spi_buf[0] = (reg << 1) & 0xFE;
	my_spi_buf[1] = tx_buf;

	return spi_write(pca9957_dev, &config, &spi_buffers);
}

/**
 * @brief Read one byte from the specified register
 *
 * @param addr 7-bit register address to be read from
 * @param rx_buf buffer where data to be read will be written to
 *
 * @retval 0 If successful.
 * @retval -errno Negative errno code on failure.
 */
int pca9957_read(uint8_t reg, uint8_t *rx_buf) {
	// ********** SPI READING **********
	// send first 7 bit with register address MSB
	// LSB set to read from device
	//reg_addr = 0x08;
	int ret;
	my_spi_buf[0] = (reg << 1) | 0x01;
	my_spi_buf[1] = 0xFF;

	ret = spi_write(pca9957_dev, &config, &spi_buffers);

	ret |= spi_read(pca9957_dev, &config, &spi_buffers);
	*rx_buf = my_spi_buf[1];
    return ret;
}
