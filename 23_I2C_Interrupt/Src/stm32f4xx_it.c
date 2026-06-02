#include "i2c_driver.h"

//void I2C1_EV_IRQHandler(void)
//{
//    if (I2C1_SR1 & (1 << 0))
//    {
//        I2C1_DR = (0x3F << 1);
//    }
//
//    if (I2C1_SR1 & (1 << 1))
//    {
//        (void)I2C1_SR1;
//        (void)I2C1_SR2;
//    }
//
//    if (I2C1_SR1 & (1 << 7))
//    {
//        I2C1_DR = 0x00; // placeholder data
//    }
//
//    if (I2C1_SR1 & (1 << 2))
//    {
//        I2C1_CR1 |= (1 << 9);
//        i2c_done = 1;
//    }
//}
