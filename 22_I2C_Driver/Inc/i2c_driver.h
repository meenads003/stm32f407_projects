#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "stm32f407xx.h"

void i2c1_init(void);
void i2c1_start(void);
void i2c1_stop(void);
void i2c1_write_address(uint8_t address);
void i2c1_write_data(uint8_t data);

#endif
