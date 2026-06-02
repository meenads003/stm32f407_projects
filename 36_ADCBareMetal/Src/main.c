#include "stm32f407_register.h"

/* ================= SIMPLE DELAY ================= */
void delay_ms(int ms)
{
    volatile int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1600; j++);
}

/* ================= UART2 INIT ================= */
void UART2_Init(void)
{
    /* Enable clocks */
    RCC_AHB1ENR |= (1 << 0);     // GPIOA
    RCC_APB1ENR |= (1 << 17);    // USART2

    /* PA2 alternate function mode */
    GPIOA_MODER &= ~(3 << 4);
    GPIOA_MODER |=  (2 << 4);

    /* AF7 for USART2 */
    GPIOA_AFRL &= ~(0xF << 8);
    GPIOA_AFRL |=  (7 << 8);

    /* Baudrate 115200 (assuming 16MHz) */
    USART2_BRR = 0x008B;

    /* Enable TX + USART */
    USART2_CR1 |= (1 << 3);     // TE
    USART2_CR1 |= (1 << 13);    // UE
}

/* ================= UART SEND CHAR ================= */
void UART_SendChar(char c)
{
    int timeout = 100000;

    while(!(USART2_SR & (1 << 7)) && timeout--);

    if(timeout > 0)
        USART2_DR = c;
}

/* ================= UART SEND STRING ================= */
void UART_SendString(char *s)
{
    while(*s)
        UART_SendChar(*s++);
}

/* ================= ADC INIT ================= */
void ADC1_Init(void)
{
    /* Enable clocks */
    RCC_AHB1ENR |= (1 << 0);     // GPIOA
    RCC_APB2ENR |= (1 << 8);     // ADC1

    /* PA1 analog mode */
    GPIOA_MODER |= (3 << 2);

    /* ADC ON */
    ADC1_CR2 |= (1 << 0);
}

/* ================= ADC READ ================= */
int ADC1_Read(void)
{
    int timeout = 100000;

    ADC1_SQR3 = 1;              // Channel 1 (PA1)

    ADC1_CR2 |= (1 << 30);      // Start conversion

    while(!(ADC1_SR & (1 << 1)) && timeout--);

    if(timeout == 0)
        return -1;

    return ADC1_DR;
}

/* ================= PRINT NUMBER ================= */
void print_num(int num)
{
    char buf[10];
    int i = 0;

    if(num == 0)
    {
        UART_SendChar('0');
        return;
    }

    if(num < 0)
    {
        UART_SendChar('-');
        num = -num;
    }

    while(num > 0)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while(i--)
        UART_SendChar(buf[i]);
}

/* ================= MAIN ================= */
int main(void)
{
    int adc;

    UART2_Init();
    ADC1_Init();

    UART_SendString("ADC STARTED\r\n");

    while(1)
    {
        adc = ADC1_Read();

        if(adc == -1)
        {
            UART_SendString("ADC ERROR\r\n");
            continue;
        }

        UART_SendString("ADC: ");
        print_num(adc);
        UART_SendString("\r\n");

        delay_ms(500);
    }
}
