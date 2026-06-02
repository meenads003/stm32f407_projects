#ifndef STM32F407XX_H
#define STM32F407XX_H

/* ================= RCC ================= */
#define RCC_BASE        0x40023800

#define RCC_AHB1ENR     (*(volatile unsigned int*)(RCC_BASE + 0x30))
#define RCC_APB1ENR     (*(volatile unsigned int*)(RCC_BASE + 0x40))
#define RCC_APB2ENR     (*(volatile unsigned int*)(RCC_BASE + 0x44))

/* ================= GPIOA ================= */
#define GPIOA_BASE      0x40020000

#define GPIOA_MODER     (*(volatile unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_OTYPER    (*(volatile unsigned int*)(GPIOA_BASE + 0x04))
#define GPIOA_OSPEEDR   (*(volatile unsigned int*)(GPIOA_BASE + 0x08))
#define GPIOA_PUPDR     (*(volatile unsigned int*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR       (*(volatile unsigned int*)(GPIOA_BASE + 0x10))
#define GPIOA_ODR       (*(volatile unsigned int*)(GPIOA_BASE + 0x14))
#define GPIOA_AFRL      (*(volatile unsigned int*)(GPIOA_BASE + 0x20))
#define GPIOA_AFRH      (*(volatile unsigned int*)(GPIOA_BASE + 0x24))

/* ================= USART2 ================= */
#define USART2_BASE     0x40004400

#define USART2_SR       (*(volatile unsigned int*)(USART2_BASE + 0x00))
#define USART2_DR       (*(volatile unsigned int*)(USART2_BASE + 0x04))
#define USART2_BRR      (*(volatile unsigned int*)(USART2_BASE + 0x08))
#define USART2_CR1      (*(volatile unsigned int*)(USART2_BASE + 0x0C))
#define USART2_CR2      (*(volatile unsigned int*)(USART2_BASE + 0x10))
#define USART2_CR3      (*(volatile unsigned int*)(USART2_BASE + 0x14))

/* ================= ADC1 ================= */
#define ADC1_BASE       0x40012000

#define ADC1_SR         (*(volatile unsigned int*)(ADC1_BASE + 0x00))
#define ADC1_CR1        (*(volatile unsigned int*)(ADC1_BASE + 0x04))
#define ADC1_CR2        (*(volatile unsigned int*)(ADC1_BASE + 0x08))
#define ADC1_SQR3       (*(volatile unsigned int*)(ADC1_BASE + 0x34))
#define ADC1_DR         (*(volatile unsigned int*)(ADC1_BASE + 0x4C))

#endif
