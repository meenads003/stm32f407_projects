#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "stm32f407xx.h"

void i2c1_init(void);
void i2c1_master_write_interrupt(uint8_t data);

#endif
