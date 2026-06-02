/*
 * stm32f407_register.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */
#ifndef STM32F407_REGISTER_H
#define STM32F407_REGISTER_H

/* ================= RCC ================= */
#define RCC_AHB1ENR   (*(volatile unsigned int*)0x40023830)
#define RCC_APB1ENR   (*(volatile unsigned int*)0x40023840)

/* ================= GPIOD ================= */
#define GPIOD_MODER   (*(volatile unsigned int*)0x40020C00)
#define GPIOD_ODR     (*(volatile unsigned int*)0x40020C14)

/* ================= TIMER2 ================= */
#define TIM2_CR1      (*(volatile unsigned int*)0x40000000)
#define TIM2_DIER     (*(volatile unsigned int*)0x4000000C)
#define TIM2_SR       (*(volatile unsigned int*)0x40000010)
#define TIM2_PSC      (*(volatile unsigned int*)0x40000028)
#define TIM2_ARR      (*(volatile unsigned int*)0x4000002C)
#define TIM2_CNT      (*(volatile unsigned int*)0x40000024)

/* Interrupt Enable Register (NVIC) */
#define NVIC_ISER0    (*(volatile unsigned int*)0xE000E100)

#endif
