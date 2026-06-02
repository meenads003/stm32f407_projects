#include "stm32f407xx.h"
#include "spi_driver.h"

void spi1_init(void)
{
    /* =========================================
       Enable clocks
    ========================================= */

    RCC_AHB1ENR |= (1 << 0);   /* GPIOA */
    RCC_AHB1ENR |= (1 << 3);   /* GPIOD */

    RCC_APB2ENR |= (1 << 12);  /* SPI1 */

    /* =========================================
       PA5 -> SPI1_SCK
       PA7 -> SPI1_MOSI
    ========================================= */

    GPIOA_MODER &= ~(3 << (5 * 2));
    GPIOA_MODER |=  (2 << (5 * 2));

    GPIOA_MODER &= ~(3 << (7 * 2));
    GPIOA_MODER |=  (2 << (7 * 2));

    /* AF5 */

    GPIOA_AFRL &= ~(0xF << (5 * 4));
    GPIOA_AFRL |=  (5 << (5 * 4));

    GPIOA_AFRL &= ~(0xF << (7 * 4));
    GPIOA_AFRL |=  (5 << (7 * 4));

    /* =========================================
       PD12 -> OUTPUT
    ========================================= */

    GPIOD_MODER &= ~(3 << (12 * 2));
    GPIOD_MODER |=  (1 << (12 * 2));

    /* =========================================
       SPI1 Configuration
    ========================================= */

    SPI1_CR1 = 0;

    /* Master mode */
    SPI1_CR1 |= (1 << 2);

    /* Baud rate */
    SPI1_CR1 |= (3 << 3);

    /* Software slave management */
    SPI1_CR1 |= (1 << 9);
    SPI1_CR1 |= (1 << 8);

    /* SPI enable */
    SPI1_CR1 |= (1 << 6);
}

void spi1_transmit(uint8_t data)
{
    /* Wait TXE flag */
    while (!(SPI1_SR & (1 << 1)));

    /* Send data */
    SPI1_DR = data;

    /* Wait until SPI not busy */
    while (SPI1_SR & (1 << 7));

    /* Transmission successful -> toggle LED */
    GPIOD_ODR ^= (1 << 12);
}
