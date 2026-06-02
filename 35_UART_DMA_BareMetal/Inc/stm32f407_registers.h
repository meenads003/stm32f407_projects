/*
 * stm32f407_registers.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */

#ifndef STM32F407_REGISTERS_H
#define STM32F407_REGISTERS_H

/**************** RCC ****************/

#define RCC_BASE            0x40023800

#define RCC_AHB1ENR         (*(volatile unsigned int*)(RCC_BASE + 0x30))
#define RCC_APB1ENR         (*(volatile unsigned int*)(RCC_BASE + 0x40))

/**************** GPIOA ****************/

#define GPIOA_BASE          0x40020000

#define GPIOA_MODER         (*(volatile unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_OTYPER        (*(volatile unsigned int*)(GPIOA_BASE + 0x04))
#define GPIOA_OSPEEDR       (*(volatile unsigned int*)(GPIOA_BASE + 0x08))
#define GPIOA_PUPDR         (*(volatile unsigned int*)(GPIOA_BASE + 0x0C))
#define GPIOA_AFRL          (*(volatile unsigned int*)(GPIOA_BASE + 0x20))

/**************** USART2 ****************/

#define USART2_BASE         0x40004400

#define USART2_SR           (*(volatile unsigned int*)(USART2_BASE + 0x00))
#define USART2_DR           (*(volatile unsigned int*)(USART2_BASE + 0x04))
#define USART2_BRR          (*(volatile unsigned int*)(USART2_BASE + 0x08))
#define USART2_CR1          (*(volatile unsigned int*)(USART2_BASE + 0x0C))
#define USART2_CR2          (*(volatile unsigned int*)(USART2_BASE + 0x10))
#define USART2_CR3          (*(volatile unsigned int*)(USART2_BASE + 0x14))

/**************** DMA1 ****************/

#define DMA1_BASE           0x40026000

#define DMA1_HISR           (*(volatile unsigned int*)(DMA1_BASE + 0x04))
#define DMA1_HIFCR          (*(volatile unsigned int*)(DMA1_BASE + 0x0C))

#define DMA1_S6CR           (*(volatile unsigned int*)(DMA1_BASE + 0xA0))
#define DMA1_S6NDTR         (*(volatile unsigned int*)(DMA1_BASE + 0xA4))
#define DMA1_S6PAR          (*(volatile unsigned int*)(DMA1_BASE + 0xA8))
#define DMA1_S6M0AR         (*(volatile unsigned int*)(DMA1_BASE + 0xAC))

#endif
