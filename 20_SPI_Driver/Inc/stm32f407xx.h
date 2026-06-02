#ifndef STM32F407XX_H
#define STM32F407XX_H

#include <stdint.h>

/* =====================================================
                        RCC
===================================================== */

#define RCC_BASE          0x40023800

#define RCC_AHB1ENR       (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_APB2ENR       (*(volatile uint32_t *)(RCC_BASE + 0x44))

/* =====================================================
                        GPIOA
===================================================== */

#define GPIOA_BASE        0x40020000

#define GPIOA_MODER       (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_AFRL        (*(volatile uint32_t *)(GPIOA_BASE + 0x20))

/* =====================================================
                        GPIOD
===================================================== */

#define GPIOD_BASE        0x40020C00

#define GPIOD_MODER       (*(volatile uint32_t *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR         (*(volatile uint32_t *)(GPIOD_BASE + 0x14))

/* =====================================================
                        SPI1
===================================================== */

#define SPI1_BASE         0x40013000

#define SPI1_CR1          (*(volatile uint32_t *)(SPI1_BASE + 0x00))
#define SPI1_SR           (*(volatile uint32_t *)(SPI1_BASE + 0x08))
#define SPI1_DR           (*(volatile uint32_t *)(SPI1_BASE + 0x0C))

#endif
