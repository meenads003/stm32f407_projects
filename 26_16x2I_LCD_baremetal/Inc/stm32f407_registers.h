/*
 * stm32f407_registers.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */

#ifndef STM32F407_REGISTERS_H
#define STM32F407_REGISTERS_H

/******************************************************************************
 * RCC
 ******************************************************************************/

#define RCC_BASE                0x40023800

#define RCC_AHB1ENR             (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define RCC_APB1ENR             (*(volatile unsigned int *)(RCC_BASE + 0x40))

/******************************************************************************
 * GPIOB
 ******************************************************************************/

#define GPIOB_BASE              0x40020400

#define GPIOB_MODER             (*(volatile unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_OTYPER            (*(volatile unsigned int *)(GPIOB_BASE + 0x04))
#define GPIOB_OSPEEDR           (*(volatile unsigned int *)(GPIOB_BASE + 0x08))
#define GPIOB_PUPDR             (*(volatile unsigned int *)(GPIOB_BASE + 0x0C))
#define GPIOB_IDR               (*(volatile unsigned int *)(GPIOB_BASE + 0x10))
#define GPIOB_ODR               (*(volatile unsigned int *)(GPIOB_BASE + 0x14))
#define GPIOB_AFRH              (*(volatile unsigned int *)(GPIOB_BASE + 0x24))

/******************************************************************************
 * I2C1
 ******************************************************************************/

#define I2C1_BASE               0x40005400

#define I2C1_CR1               (*(volatile unsigned int *)(I2C1_BASE + 0x00))
#define I2C1_CR2               (*(volatile unsigned int *)(I2C1_BASE + 0x04))
#define I2C1_OAR1              (*(volatile unsigned int *)(I2C1_BASE + 0x08))
#define I2C1_DR                (*(volatile unsigned int *)(I2C1_BASE + 0x10))
#define I2C1_SR1               (*(volatile unsigned int *)(I2C1_BASE + 0x14))
#define I2C1_SR2               (*(volatile unsigned int *)(I2C1_BASE + 0x18))
#define I2C1_CCR               (*(volatile unsigned int *)(I2C1_BASE + 0x1C))
#define I2C1_TRISE             (*(volatile unsigned int *)(I2C1_BASE + 0x20))

/******************************************************************************
 * RCC Enable Bits
 ******************************************************************************/

#define GPIOBEN_BIT             1
#define I2C1EN_BIT              21

/******************************************************************************
 * I2C CR1 Bits
 ******************************************************************************/

#define I2C_PE                  0
#define I2C_START               8
#define I2C_STOP                9

/******************************************************************************
 * I2C SR1 Bits
 ******************************************************************************/

#define I2C_SB                  0
#define I2C_ADDR                1
#define I2C_TXE                 7
#define I2C_BTF                 2

#endif
