#include "stm32f407xx.h"
#include "spi_driver.h"

volatile uint8_t tx_data;

void spi1_init(void)
{
    RCC_AHB1ENR |= (1 << 0);
    RCC_AHB1ENR |= (1 << 3);
    RCC_APB2ENR |= (1 << 12);

    /* GPIO config */
    GPIOA_MODER &= ~(3 << (5 * 2));
    GPIOA_MODER |=  (2 << (5 * 2));

    GPIOA_MODER &= ~(3 << (7 * 2));
    GPIOA_MODER |=  (2 << (7 * 2));

    GPIOA_AFRL &= ~(0xF << (5 * 4));
    GPIOA_AFRL |=  (5 << (5 * 4));

    GPIOA_AFRL &= ~(0xF << (7 * 4));
    GPIOA_AFRL |=  (5 << (7 * 4));

    /* LED */
    GPIOD_MODER &= ~(3 << (12 * 2));
    GPIOD_MODER |=  (1 << (12 * 2));

    /* SPI config */
    SPI1_CR1 = 0;
    SPI1_CR1 |= (1 << 2);   // master
    SPI1_CR1 |= (3 << 3);   // baud
    SPI1_CR1 |= (1 << 9);   // SSM
    SPI1_CR1 |= (1 << 8);   // SSI

    /* enable TXE interrupt */
    SPI1_CR2 |= (1 << 7);

    SPI1_CR1 |= (1 << 6);   // SPI enable

    NVIC_ISER1 |= (1 << 3);
}

void spi1_send_it(uint8_t data)
{
    tx_data = data;
    SPI1_DR = tx_data;
}
