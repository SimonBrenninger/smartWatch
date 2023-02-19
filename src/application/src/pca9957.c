#include "header.h"
#include "pca9957.h"

//#define SET_FAULTY

LOG_MODULE_DECLARE(SmartWatchDemo, DEMO_LOG_LEVEL);

// SPI struct definitions

static const struct device *spi_dev = DEVICE_DT_GET(SPI_NODE);

uint8_t my_spi_buf[2];

struct spi_config config = {
	.frequency = 1000000,
	.operation = SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8),
	.cs = SPI_CS_CONTROL_PTR_DT(DT_NODELABEL(my_spi_dev), 0),
};

struct spi_buf spi_buffer = {
	.buf = my_spi_buf,
	.len = 2 * sizeof(my_spi_buf[0])
};
struct spi_buf_set spi_buffers = {
	.buffers = &spi_buffer,
	.count = 1
};

void myspi_write(uint8_t addr, uint8_t data)
{
	// ********** WRITING **********
	// send first 7 bit with register address MSB
	// LSB reset to write from device
	my_spi_buf[0] = (addr << 1) & (0xFE);

	// add another byte to be written into given register
	my_spi_buf[1] = data;

	spi_write(spi_dev, &config, &spi_buffers);
}

uint8_t myspi_read(uint8_t addr)
{
	// ********** READING **********
	// send first 7 bit with register address MSB
	// LSB set to read from device
	//reg_addr = 0x08;
	my_spi_buf[0] = (addr << 1) | (0b1);

	// add one byte of "dummy" data (only 1s)
	my_spi_buf[1] = 0xFF;

	spi_write(spi_dev, &config, &spi_buffers);

	k_msleep(1);

	// send "dummy" data (all 1s) to receive data
	// automatically handled by zephyr
	my_spi_buf[0] = 0x00;
	my_spi_buf[1] = 0x00;
	spi_read(spi_dev, &config, &spi_buffers);

	// received data stored in buf[1]
	return my_spi_buf[1];
}

void spi_test(void)
{
	uint8_t reg_addr;
	uint8_t data;

	LOG_DBG("starting spi test...");

	if(!device_is_ready(spi_dev))
	{
		LOG_ERR("SPI not ready!\n");
		return;
	}

	int test_led = 1;
	test_led %= 24;

	
	// check for error in MODE2 (0x01) bit 6
	reg_addr = 0x01; // MODE2
	data = myspi_read(reg_addr);

	if(data & BIT(6))
	{
		LOG_WRN("ERROR bit set in SPI device");
		gpio_pin_set_dt(&led, 1);
		//return;
	}
	k_msleep(1);

	/* disable auto-switchoff */
	//data = data | BIT(3);
	//myspi_write(reg_addr, data);

	/* set output current for all drivers */
	// set output gain (IREFALL)
	reg_addr = 0x6B;	// IREFALL
	data = 0x10;
	myspi_write(reg_addr, data);
	k_msleep(1);

	/* enable all drivers */
	reg_addr = 0x6A; // PWMALL
	data = 0x08;
	myspi_write(reg_addr, data);
	k_msleep(1);

	/* check for error in MODE2 (0x01) bit 6 */
	reg_addr = 0x01; // MODE2
	data = myspi_read(reg_addr);

	if(data & BIT(6))
	{
		gpio_pin_set_dt(&led, 1);
		LOG_WRN("ERROR bit in MODE2 set");

		reg_addr = 0x02;
		int idx = 0;
		while (idx < 6)
		{
			data = myspi_read(reg_addr+idx);
			if(data == 0x0)
				LOG_DBG("EFLAG%d: no error found", idx);
			else
				LOG_WRN("EFLAG%d: found non-zero error: 0x%x", idx, data);
			idx++;
		}
	}
#ifdef SET_FAULTY
    test_faulty();
#endif

	k_msleep(100);
	printk("\n");
	return;
}

void test_faulty(void)
{
    //uint8_t reg, data;

    // disable all outputs
    myspi_write(0x08, 0x00);
    myspi_write(0x09, 0x00);
    myspi_write(0x0A, BIT(2));    //LEDOUT2
    myspi_write(0x0B, 0x00);
    myspi_write(0x0C, 0x00);
    myspi_write(0x0D, 0x00);

    return;
}

void spi_init(void)
{

}