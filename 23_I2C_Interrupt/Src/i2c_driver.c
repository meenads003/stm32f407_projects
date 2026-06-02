#include "i2c_driver.h"

volatile uint8_t tx_data;

void i2c1_init(void)
{
    /******** CLOCK ENABLE ********/
    RCC_AHB1ENR |= (1 << 1);
    RCC_APB1ENR |= (1 << 21);

    /******** PB8 SCL PB9 SDA ********/

    GPIOB_MODER &= ~(0xF << 16);
    GPIOB_MODER |=  (0xA << 16);

    GPIOB_OTYPER |= (1 << 8) | (1 << 9);

    GPIOB_PUPDR &= ~(0xF << 16);
    GPIOB_PUPDR |=  (0x5 << 16);

    GPIOB_OSPEEDR |= (0xF << 16);

    GPIOB_AFRH &= ~(0xFF);
    GPIOB_AFRH |=  (0x44);

    /******** I2C CONFIG ********/

    I2C1_CR1 &= ~(1 << 0);

    I2C1_CR2 = 16;

    I2C1_CCR = 80;

    I2C1_TRISE = 17;

    /******** ENABLE INTERRUPTS ********/

    I2C1_CR2 |= (1 << 9);
    I2C1_CR2 |= (1 << 10);

    NVIC_ISER0 |= (1 << 31);

    I2C1_CR1 |= (1 << 0);
}

void i2c1_master_write_interrupt(uint8_t data)
{
    tx_data = data;

    I2C1_CR1 |= (1 << 8);
}

void I2C1_EV_IRQHandler(void)
{
    static uint8_t state = 0;

    if(I2C1_SR1 & (1 << 0))
    {
        I2C1_DR = 0x7E;
        state = 1;
    }

    else if((I2C1_SR1 & (1 << 1)) && state == 1)
    {
        (void)I2C1_SR1;
        (void)I2C1_SR2;

        I2C1_DR = tx_data;

        state = 2;
    }

    else if((I2C1_SR1 & (1 << 7)) && state == 2)
    {
        I2C1_CR1 |= (1 << 9);

        state = 0;
    }
}
