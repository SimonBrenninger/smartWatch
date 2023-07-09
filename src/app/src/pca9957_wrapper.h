/*
 * Copyright (c) 2023 Simon Brenninger
 *
 * SPDX-License-Identifier: GPLv3
 */

#include "pca9957.h"

#ifndef PCA9957_WRAPPER_INCLUDED
#define PCA9957_WRAPPER_INCLUDED

// register definition

#define PCA9957_MODE_BASE           0x00
#define PCA9957_EFLAG_BASE          0x02
#define PCA9957_LEDOUT_BASE         0x08
#define PCA9957_PWM_BASE            0x10
#define PCA9957_IREF_BASE           0x28


// MODE1 register
#define PCA9957_MODE1               PCA9957_MODE_BASE
// MODE1 bit definitios
#define PCA9957_MODE1_SLEEP         BIT(4)
#define PCA9957_LOW_POWER_EN        0x01
#define PCA9957_LOW_POWER_DIS       0x00


// MODE2 register
#define PCA9957_MODE2               PCA9957_MODE_BASE + 0x01
// MODE2 bit definitions
#define PCA9957_MODE2_OVERTEMP              BIT(7)
#define PCA9957_MODE2_ERROR                 BIT(6)
#define PCA9957_MODE2_DMBLK                 BIT(5)
#define PCA9957 MODE2_CLRERR                BIT(4)
#define PCA9957_MODE2_AUTO_SWITCHOFF_DIS    BIT(3)
#define PCA9957_MODE2_EXP_EN                BIT(2)


#define PCA9957_EFLAG0              PCA9957_EFLAG_BASE
#define PCA9957_EFLAG1              PCA9957_EFLAG_BASE + 0x01
#define PCA9957_EFLAG2              PCA9957_EFLAG_BASE + 0x02
#define PCA9957_EFLAG3              PCA9957_EFLAG_BASE + 0x03
#define PCA9957_EFLAG4              PCA9957_EFLAG_BASE + 0x04
#define PCA9957_EFLAG5              PCA9957_EFLAG_BASE + 0x05
#define PCA9957_EFLAG(n)            PCA9957_EFLAG_BASE + (n % 0x06)


// LEDOUT registers
#define PCA9957_LEDOUT0             PCA9957_LEDOUT_BASE
#define PCA9957_LEDOUT1             PCA9957_LEDOUT_BASE + 0x01
#define PCA9957_LEDOUT2             PCA9957_LEDOUT_BASE + 0x02
#define PCA9957_LEDOUT3             PCA9957_LEDOUT_BASE + 0x03
#define PCA9957_LEDOUT4             PCA9957_LEDOUT_BASE + 0x04
#define PCA9957_LEDOUT5             PCA9957_LEDOUT_BASE + 0x05
#define PCA9957_LEDOUT(n)           PCA9957_LEDOUT_BASE + (n % 0x06)
// LEDOUT bit definitions
#define PCA9957_LEDMODE_OFF         0x00
#define PCA9957_LEDMODE_ON          0x01
#define PCA9957_LEDMODE_PWM         0x02
#define PCA9957_LEDMODE_GROUP       0x03
// wrapper definitions
#define PCA9957_NUM_LEDOUT_REGS     6
#define PCA9957_LEDOUT_REGSIZE      8
#define PCA9957_LEDOUT_REG(n)       (int)(PCA9957_LEDMODE_SIZE * n / PCA9957_LEDOUT_REGSIZE)
#define PCA9957_LEDMODE_SIZE        2
#define PCA9957_LEDMODE_POS(n)      (PCA9957_LEDMODE_SIZE * n) % PCA9957_LEDOUT_REGSIZE
#define PCA9957_LEDMODE_MSK         0x03

#define PCA9957_NUM_LEDS            24
#define PCA9957_LED(n)              BIT((n % PCA9957_NUM_LEDS))
#define PCA9957_LEDS_MSK            0xFFFFFF


#define PCA9957_PWM0                PCA9957_PWM_BASE
#define PCA9957_PWM1                PCA9957_PWM_BASE + 0x01
#define PCA9957_PWM2                PCA9957_PWM_BASE + 0x02
#define PCA9957_PWM3                PCA9957_PWM_BASE + 0x03
#define PCA9957_PWM4                PCA9957_PWM_BASE + 0x04
#define PCA9957_PWM5                PCA9957_PWM_BASE + 0x05
#define PCA9957_PWM6                PCA9957_PWM_BASE + 0x06
#define PCA9957_PWM7                PCA9957_PWM_BASE + 0x07
#define PCA9957_PWM8                PCA9957_PWM_BASE + 0x08
#define PCA9957_PWM9                PCA9957_PWM_BASE + 0x09
#define PCA9957_PWM10               PCA9957_PWM_BASE + 0x0A
#define PCA9957_PWM11               PCA9957_PWM_BASE + 0x0B
#define PCA9957_PWM12               PCA9957_PWM_BASE + 0x0C
#define PCA9957_PWM13               PCA9957_PWM_BASE + 0x0D
#define PCA9957_PWM14               PCA9957_PWM_BASE + 0x0E
#define PCA9957_PWM15               PCA9957_PWM_BASE + 0x0F
#define PCA9957_PWM16               PCA9957_PWM_BASE + 0x10
#define PCA9957_PWM17               PCA9957_PWM_BASE + 0x11
#define PCA9957_PWM18               PCA9957_PWM_BASE + 0x12
#define PCA9957_PWM19               PCA9957_PWM_BASE + 0x13
#define PCA9957_PWM20               PCA9957_PWM_BASE + 0x14
#define PCA9957_PWM21               PCA9957_PWM_BASE + 0x15
#define PCA9957_PWM22               PCA9957_PWM_BASE + 0x16
#define PCA9957_PWM23               PCA9957_PWM_BASE + 0x17
#define PCA9957_PWM(n)              PCA9957_PWM_BASE + (n % 0x18)


#define PCA9957_IREF0               PCA9957_IREF_BASE
#define PCA9957_IREF1               PCA9957_IREF_BASE + 0x01
#define PCA9957_IREF2               PCA9957_IREF_BASE + 0x02
#define PCA9957_IREF3               PCA9957_IREF_BASE + 0x03
#define PCA9957_IREF4               PCA9957_IREF_BASE + 0x04
#define PCA9957_IREF5               PCA9957_IREF_BASE + 0x05
#define PCA9957_IREF6               PCA9957_IREF_BASE + 0x06
#define PCA9957_IREF7               PCA9957_IREF_BASE + 0x07
#define PCA9957_IREF8               PCA9957_IREF_BASE + 0x08
#define PCA9957_IREF9               PCA9957_IREF_BASE + 0x09
#define PCA9957_IREF10              PCA9957_IREF_BASE + 0x0A
#define PCA9957_IREF11              PCA9957_IREF_BASE + 0x0B
#define PCA9957_IREF12              PCA9957_IREF_BASE + 0x0C
#define PCA9957_IREF13              PCA9957_IREF_BASE + 0x0D
#define PCA9957_IREF14              PCA9957_IREF_BASE + 0x0E
#define PCA9957_IREF15              PCA9957_IREF_BASE + 0x0F
#define PCA9957_IREF16              PCA9957_IREF_BASE + 0x10
#define PCA9957_IREF17              PCA9957_IREF_BASE + 0x11
#define PCA9957_IREF18              PCA9957_IREF_BASE + 0x12
#define PCA9957_IREF19              PCA9957_IREF_BASE + 0x13
#define PCA9957_IREF20              PCA9957_IREF_BASE + 0x14
#define PCA9957_IREF21              PCA9957_IREF_BASE + 0x15
#define PCA9957_IREF22              PCA9957_IREF_BASE + 0x16
#define PCA9957_IREF23              PCA9957_IREF_BASE + 0x17
#define PCA9957_IREF(n)             PCA9957_IREF_BASE + (n % 0x18)


#define PCA9957_RAMP_RATE_GRP0      0x40
#define PCA9957_STEP_TIME_GRP0      0x41
#define PCA9957_HOLD_CNTL_GRP0      0x42
#define PCA9957_IREF_GRP0           0x43

#define PCA9957_RAMP_RATE_GRP1      0x44
#define PCA9957_STEP_TIME_GRP1      0x45
#define PCA9957_HOLD_CNTL_GRP1      0x46
#define PCA9957_IREF_GRP1           0x47

#define PCA9957_RAMP_RATE_GRP2      0x48
#define PCA9957_STEP_TIME_GRP2      0x49
#define PCA9957_HOLD_CNTL_GRP2      0x4A
#define PCA9957_IREF_GRP2           0x4B

#define PCA9957_RAMP_RATE_GRP3      0x4C
#define PCA9957_STEP_TIME_GRP3      0x4D
#define PCA9957_HOLD_CNTL_GRP3      0x4E
#define PCA9957_IREF_GRP3           0x4F

#define PCA9957_RAMP_RATE_GRP4      0x50
#define PCA9957_STEP_TIME_GRP4      0x51
#define PCA9957_HOLD_CNTL_GRP4      0x52
#define PCA9957_IREF_GRP4           0x53

#define PCA9957_RAMP_RATE_GRP5      0x54
#define PCA9957_STEP_TIME_GRP5      0x55
#define PCA9957_HOLD_CNTL_GRP5      0x56
#define PCA9957_IREF_GRP5           0x57


#define PCA9957_GRAD_MODE_SEL0      0x58
#define PCA9957_GRAD_MODE_SEL1      0x59
#define PCA9957_GRAD_MODE_SEL2      0x5A

#define PCA9957_GRAD_GRP_SEL0       0x5B
#define PCA9957_GRAD_GRP_SEL1       0x5B
#define PCA9957_GRAD_GRP_SEL2       0x5B
#define PCA9957_GRAD_GRP_SEL3       0x5B
#define PCA9957_GRAD_GRP_SEL4       0x5B
#define PCA9957_GRAD_GRP_SEL5       0x60
#define PCA9957_GRAD_GRP_SEL6       0x61
#define PCA9957_GRAD_GRP_SEL7       0x62
#define PCA9957_GRAD_GRP_SEL8       0x63
#define PCA9957_GRAD_GRP_SEL9       0x64
#define PCA9957_GRAD_GRP_SEL10      0x65
#define PCA9957_GRAD_GRP_SEL11      0x66

#define PCA9957_GRAD_CNTL0          0x67
#define PCA9957_GRAD_CNTL1          0x68


#define PCA9957_OFFSET              0x69
#define PCA9957_PWMALL              0x6A
#define PCA9957_IREFALL             0x6B


// ERROR definitions
#define ERR_PCA9957COMMON           BIT(1)

// Prototype definitions

int pca9957_set_power_mode(uint8_t low_power);
int pca9957_get_power_mode(uint8_t *low_power);
int pca9957_get_status(uint8_t *status);
int pca9957_check_error(uint8_t *error);
int pca9957_set_led_mode(uint32_t leds, uint8_t mode);
int pca9957_set_led_pwm(uint32_t leds, uint8_t pwm);
int pca9957_set_led_current(uint32_t leds, uint8_t current);

int pca9957_write(uint8_t reg, uint8_t tx_buf);
int pca9957_read(uint8_t reg, uint8_t *rx_buf);

#endif// PCA9957_WRAPPER_INCLUDED