#include "stm32f407xx.h"

void EXTI15_10_IRQHandler(void)
{
    GPIOD->ODR ^= (1 << 12);
}

int main(void)
{
    RCC->AHB1ENR |= (1 << 3);
    GPIOD->MODER |= (1 << (12 * 2));

    while (1);
}
