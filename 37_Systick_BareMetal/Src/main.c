#include "stm32f407_register.h"

/* ================= GLOBAL TICK ================= */
volatile unsigned int msTicks = 0;

/* ================= SysTick INTERRUPT ================= */
void SysTick_Handler(void)
{
    msTicks++;
}

/* ================= SysTick INIT ================= */
void SysTick_Init(void)
{
    SysTick_LOAD = 16000 - 1;   // 1ms tick (16MHz HSI)
    SysTick_VAL  = 0;           // clear counter

    SysTick_CTRL = (1 << 0) |   // ENABLE
                   (1 << 1) |   // TICKINT (interrupt enable)
                   (1 << 2);    // CLKSOURCE = CPU clock
}

/* ================= DELAY ================= */
void delay_ms(unsigned int ms)
{
    unsigned int start = msTicks;
    while((msTicks - start) < ms);
}

/* ================= LED INIT ================= */
void LED_Init(void)
{
    RCC_AHB1ENR |= (1 << 3);   // Enable GPIOD clock

    // PD12 output mode
    GPIOD_MODER &= ~(3 << (12 * 2));
    GPIOD_MODER |=  (1 << (12 * 2));
}

/* ================= LED TOGGLE ================= */
void LED_Toggle(void)
{
    GPIOD_ODR ^= (1 << 12);
}

/* ================= MAIN ================= */
int main(void)
{
    LED_Init();
    SysTick_Init();

    while(1)
    {
        LED_Toggle();
        delay_ms(500);   // 500ms blink
    }
}
