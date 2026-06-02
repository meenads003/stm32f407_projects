#include "uart.h"

void delay(volatile int count)
{
    while (count--);
}

int main(void)
{
    UART2_Init();

    UART2_SendString("UART Interrupt Ready\r\n");

    while (1)
    {
        UART2_SendString("UART Interrupt\r\n");
        delay(2000000);
    }
}
