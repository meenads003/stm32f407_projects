/*
 * i2c_driver.c
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */

#include "i2c_driver.h"

void delay_ms(unsigned int ms)
{
    volatile unsigned int i;
    volatile unsigned int j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 16000; j++)
        {
        }
    }
}

void I2C1_Init(void)
{
    /* Enable GPIOB clock */
    RCC_AHB1ENR |= (1 << GPIOBEN_BIT);

    /* Enable I2C1 clock */
    RCC_APB1ENR |= (1 << I2C1EN_BIT);

    /* PB8 Alternate Function */
    GPIOB_MODER &= ~(3 << 16);
    GPIOB_MODER |=  (2 << 16);

    /* PB9 Alternate Function */
    GPIOB_MODER &= ~(3 << 18);
    GPIOB_MODER |=  (2 << 18);

    /* Open Drain */
    GPIOB_OTYPER |= (1 << 8);
    GPIOB_OTYPER |= (1 << 9);

    /* Pull-Up */
    GPIOB_PUPDR &= ~(3 << 16);
    GPIOB_PUPDR |=  (1 << 16);

    GPIOB_PUPDR &= ~(3 << 18);
    GPIOB_PUPDR |=  (1 << 18);

    /* AF4 */
    GPIOB_AFRH &= ~(0xF << 0);
    GPIOB_AFRH |=  (4 << 0);

    GPIOB_AFRH &= ~(0xF << 4);
    GPIOB_AFRH |=  (4 << 4);

    /* Disable I2C */
    I2C1_CR1 = 0;

    /* APB1 = 16MHz */
    I2C1_CR2 = 16;

    /* 100kHz */
    I2C1_CCR = 80;

    /* TRISE */
    I2C1_TRISE = 17;

    /* Enable I2C */
    I2C1_CR1 |= (1 << I2C_PE);
}

void I2C1_Start(void)
{
    I2C1_CR1 |= (1 << I2C_START);

    while(!(I2C1_SR1 & (1 << I2C_SB)));
}

void I2C1_Stop(void)
{
    I2C1_CR1 |= (1 << I2C_STOP);
}

void I2C1_Address(unsigned char address)
{
    I2C1_DR = address;

    while(!(I2C1_SR1 & (1 << I2C_ADDR)));

    (void)I2C1_SR1;
    (void)I2C1_SR2;
}

void I2C1_WriteByte(unsigned char data)
{
    while(!(I2C1_SR1 & (1 << I2C_TXE)));

    I2C1_DR = data;

    while(!(I2C1_SR1 & (1 << I2C_BTF)));
}

void I2C1_Write(unsigned char address,
                unsigned char data)
{
    I2C1_Start();

    I2C1_Address(address << 1);

    I2C1_WriteByte(data);

    I2C1_Stop();
}
