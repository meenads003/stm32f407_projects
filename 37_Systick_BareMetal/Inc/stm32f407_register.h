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

/* ================= GPIO D ================= */
#define GPIOD_MODER   (*(volatile unsigned int*)0x40020C00)
#define GPIOD_ODR     (*(volatile unsigned int*)0x40020C14)

/* ================= SysTick ================= */
#define SysTick_CTRL  (*(volatile unsigned int*)0xE000E010)
#define SysTick_LOAD  (*(volatile unsigned int*)0xE000E014)
#define SysTick_VAL   (*(volatile unsigned int*)0xE000E018)

#endif
