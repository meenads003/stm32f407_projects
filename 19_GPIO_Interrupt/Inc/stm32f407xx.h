#ifndef STM32F407XX_H
#define STM32F407XX_H

#include <stdint.h>

#define PERIPH_BASE     0x40000000UL
#define AHB1_BASE       (PERIPH_BASE + 0x00020000UL)
#define APB2_BASE       (PERIPH_BASE + 0x00010000UL)

#define RCC_BASE        (AHB1_BASE + 0x3800)
#define GPIOA_BASE      (AHB1_BASE + 0x0000)
#define GPIOC_BASE      (AHB1_BASE + 0x0800)
#define GPIOD_BASE      (AHB1_BASE + 0x0C00)
#define SYSCFG_BASE     (APB2_BASE + 0x3800)
#define EXTI_BASE       (APB2_BASE + 0x3C00)

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];
} SYSCFG_TypeDef;

typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} EXTI_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
} RCC_TypeDef;

/* Pointers */
#define RCC     ((RCC_TypeDef *)RCC_BASE)
#define GPIOC   ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *)GPIOD_BASE)
#define SYSCFG  ((SYSCFG_TypeDef *)SYSCFG_BASE)
#define EXTI    ((EXTI_TypeDef *)EXTI_BASE)

/* NVIC */
#define NVIC_ISER1 (*(volatile uint32_t *)0xE000E104)

#endif
