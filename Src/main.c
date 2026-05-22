#include "uart.h"

void delay(volatile int count)
{
    while (count--);
}

int main(void)
{
    UART2_Init();

    UART2_SendString("UART Baremetal STM32F407 Ready!\r\n");

    while (1)
    {
        UART2_SendString("UART_Driver\r\n");
        delay(1000000);
    }
}
