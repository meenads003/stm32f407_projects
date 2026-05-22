#include "uart.h"

/* USART2 base = 0x40004400 */

#define USART2EN   (1 << 17)   // APB1ENR bit for USART2
#define GPIOAEN    (1 << 0)    // AHB1ENR bit for GPIOA

void UART2_Init(void)
{
    /* 1. Enable clock for GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* 2. Enable clock for USART2 */
    RCC->APB1ENR |= USART2EN;

    /* 3. Set PA2 = AF mode (TX), PA3 = AF mode (RX) */
    GPIOA->MODER &= ~(3 << (2 * 2));
    GPIOA->MODER |=  (2 << (2 * 2));   // PA2 AF

    GPIOA->MODER &= ~(3 << (3 * 2));
    GPIOA->MODER |=  (2 << (3 * 2));   // PA3 AF

    /* 4. Select AF7 for USART2 */
    GPIOA->AFR[0] |= (7 << (4 * 2));   // PA2 AF7
    GPIOA->AFR[0] |= (7 << (4 * 3));   // PA3 AF7

    /* 5. Configure UART parameters */
    USART2->BRR = 0x8B;   // 16 MHz / 115200 ≈ 0x8B (approx)

    USART2->CR1 = (1 << 13) | (1 << 3) | (1 << 2);
    // UE = USART enable
    // TE = transmit enable
    // RE = receive enable
}

void UART2_SendChar(char c)
{
    while (!(USART2->SR & (1 << 7))); // wait TXE
    USART2->DR = c;
}

void UART2_SendString(char *str)
{
    while (*str)
    {
        UART2_SendChar(*str++);
    }
}
