#include "stm32f407xx.h"

void SPI1_IRQHandler(void)
{
    if (SPI1_SR & (1 << 1))   // TXE
    {
        /* disable TXE interrupt to avoid repeated firing */
        SPI1_CR2 &= ~(1 << 7);

        /* toggle LED ONCE per interrupt */
        GPIOD_ODR ^= (1 << 12);
    }
}
