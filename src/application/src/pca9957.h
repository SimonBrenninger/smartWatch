#ifndef PCA9957_INCLUDED
#define PCA9957_INCLUDED

// register definition

#define MODE_BASE       0x00
#define EFLAG_BASE      0x02
#define LEDOUT_BASE     0x08
#define PWM_BASE        0x10
#define IREF_BASE       0x28

#define MODE(n)         MODE_BASE + ((n-1) % 2)
#define EFLAG(n)        EFLAG_BASE + (n % 6)
#define LEDOUT(n)       LEDOUT_BASE + (n % 6)
#define PWM(n)          PWM_BASE + (n % 24)
#define IREF(n)         IREF_BASE + (n % 24)

#define OFFSET          0x69
#define PWMALL          0x6A
#define IREFALL         0x6B

// MODE1 bit definitions
#define MODE1_SLEEP     BIT(4)

// MODE2 bit definitions
#define MODE2_OVERTEMP              BIT(7)
#define MODE2_ERROR                 BIT(6)
#define MODE2_DMBLK                 BIT(5)
#define MODE2_CLRERR                BIT(4)
#define MODE2_AUTO_SWITCHOFF_DIS    BIT(3)
#define MODE2_EXP_EN                BIT(2)


void myspi_write(uint8_t addr, uint8_t data);
uint8_t myspi_read(uint8_t addr);
void spi_test(void);
void test_faulty(void);
void spi_init(void);

#endif // PCA9957_INCLUDED