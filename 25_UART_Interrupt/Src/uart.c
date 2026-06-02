#include "uart.h"

volatile char rx_data;

void UART2_Init(void)
{
    /* Enable clocks */
    RCC->AHB1ENR |= (1 << 0);     // GPIOA
    RCC->APB1ENR |= (1 << 17);    // USART2

    /* PA2, PA3 -> AF mode */
    GPIOA->MODER &= ~(3 << (2 * 2));
    GPIOA->MODER |=  (2 << (2 * 2));

    GPIOA->MODER &= ~(3 << (3 * 2));
    GPIOA->MODER |=  (2 << (3 * 2));

    /* AF7 for USART2 */
    GPIOA->AFR[0] |= (7 << (4 * 2));
    GPIOA->AFR[0] |= (7 << (4 * 3));

    /* Baud rate = 115200 (16 MHz assumption) */
    USART2->BRR = 0x8B;

    /* Enable RX interrupt + TX + RX + USART */
    USART2->CR1 = (1 << 13) | (1 << 2) | (1 << 3) | (1 << 5);
    // UE = 13
    // RE = 2
    // TE = 3
    // RXNEIE = 5 (RECEIVE INTERRUPT)

    /* Enable NVIC interrupt for USART2 */
    *(volatile uint32_t *)0xE000E104 |= (1 << 6);
    // IRQ38 (USART2) → ISER1 bit 6
}

void UART2_SendChar(char c)
{
    while (!(USART2->SR & (1 << 7))); // TXE
    USART2->DR = c;
}

void UART2_SendString(char *str)
{
    while (*str)
        UART2_SendChar(*str++);
}

/* Called from ISR file */
void UART2_IRQHandler(void)
{
    if (USART2->SR & (1 << 5))   // RXNE flag
    {
        rx_data = USART2->DR;    // read data clears flag

        UART2_SendChar(rx_data); // echo back
    }
}
