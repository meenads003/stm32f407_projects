#include "gpio.h"

#define LED_PIN 12
#define BTN_PIN 13
void EXTI15_10_IRQHandler(void);
void GPIO_Init(void)
{
    /* 1. Enable clocks */
    RCC->AHB1ENR |= (1 << 2);   // GPIOC
    RCC->AHB1ENR |= (1 << 3);   // GPIOD
    RCC->APB2ENR |= (1 << 14);  // SYSCFG

    /* small delay for clock stabilization */
    for (volatile int i = 0; i < 1000; i++);

    /* 2. LED PD12 output */
    GPIOD->MODER &= ~(3 << (LED_PIN * 2));
    GPIOD->MODER |=  (1 << (LED_PIN * 2));

    /* 3. PC13 input */
    GPIOC->MODER &= ~(3 << (BTN_PIN * 2));

    /* IMPORTANT: pull-up enabled */
    GPIOC->PUPDR &= ~(3 << (BTN_PIN * 2));
    GPIOC->PUPDR |=  (1 << (BTN_PIN * 2));

    /* 4. EXTI mapping: PC13 → EXTI13 */
    SYSCFG->EXTICR[3] &= ~(0xF << 4);
    SYSCFG->EXTICR[3] |=  (0x2 << 4);

    /* 5. EXTI config */
    EXTI->IMR  |= (1 << BTN_PIN);
    EXTI->FTSR |= (1 << BTN_PIN);
    EXTI->RTSR &= ~(1 << BTN_PIN);

    /* CLEAR pending flag BEFORE enabling NVIC */
    EXTI->PR = (1 << BTN_PIN);

    /* 6. NVIC enable EXTI15_10 IRQ */
    NVIC_ISER1 |= (1 << 8);
}

void LED_Toggle(void)
{
    GPIOD->ODR ^= (1 << LED_PIN);
}
