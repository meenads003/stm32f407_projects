/*
 * i2c_driver.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */
#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include "stm32f407_registers.h"

/* Initialize GPIOB and I2C1 */
void I2C1_Init(void);

/* Generate START condition */
void I2C1_Start(void);

/* Generate STOP condition */
void I2C1_Stop(void);

/* Send slave address */
void I2C1_Address(unsigned char address);

/* Write one byte */
void I2C1_WriteByte(unsigned char data);

/* Write data to slave */
void I2C1_Write(unsigned char address,
                unsigned char data);

/* Simple delay */
void delay_ms(unsigned int ms);

#endif
