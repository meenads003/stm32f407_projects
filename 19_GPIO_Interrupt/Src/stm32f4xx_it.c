#include "gpio.h"

/* MUST match vector table symbol EXACTLY */
void EXTI15_10_IRQHandler(void)
{
    /* check pending bit */
    if (EXTI->PR & (1 << 13))
    {
        EXTI->PR = (1 << 13);   // clear flag
        LED_Toggle();          // toggle LED
    }
}
