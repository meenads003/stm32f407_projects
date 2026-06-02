#include "i2c_driver.h"

void i2c1_init(void)
{
    /******** Enable Clocks ********/
    RCC_AHB1ENR |= (1 << 1);   // GPIOB clock
    RCC_APB1ENR |= (1 << 21);  // I2C1 clock

    /******** PB8 -> SCL, PB9 -> SDA ********/

    // Alternate function mode
    GPIOB_MODER &= ~(0xF << 16);
    GPIOB_MODER |=  (0xA << 16);

    // Open drain
    GPIOB_OTYPER |= (1 << 8);
    GPIOB_OTYPER |= (1 << 9);

    // Pull-up
    GPIOB_PUPDR &= ~(0xF << 16);
    GPIOB_PUPDR |=  (0x5 << 16);

    // High speed
    GPIOB_OSPEEDR |= (0xF << 16);

    // AF4 for I2C
    GPIOB_AFRH &= ~(0xFF);
    GPIOB_AFRH |=  (0x44);

    /******** I2C Configuration ********/

    I2C1_CR1 &= ~(1 << 0);

    I2C1_CR2 = 16;

    I2C1_CCR = 80;

    I2C1_TRISE = 17;

    I2C1_CR1 |= (1 << 0);
}

void i2c1_start(void)
{
    I2C1_CR1 |= (1 << 8);

    while(!(I2C1_SR1 & (1 << 0)));

    (void)I2C1_SR1;
}

void i2c1_stop(void)
{
    I2C1_CR1 |= (1 << 9);
}

void i2c1_write_address(uint8_t address)
{
    I2C1_DR = address;

    while(!(I2C1_SR1 & (1 << 1)));

    (void)I2C1_SR1;
    (void)I2C1_SR2;
}

void i2c1_write_data(uint8_t data)
{
    while(!(I2C1_SR1 & (1 << 7)));

    I2C1_DR = data;

    while(!(I2C1_SR1 & (1 << 2)));
}
