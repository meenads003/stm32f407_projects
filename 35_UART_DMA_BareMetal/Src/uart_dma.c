/*
 * uart_dma.c
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */


#include "stm32f407_registers.h"
#include "uart_dma.h"

void delay_ms(unsigned int ms)
{
    volatile unsigned int i;
    volatile unsigned int j;

    for(i=0;i<ms;i++)
    {
        for(j=0;j<16000;j++)
        {
        }
    }
}

void UART2_Init(void)
{
    /* GPIOA Clock */
    RCC_AHB1ENR |= (1<<0);

    /* USART2 Clock */
    RCC_APB1ENR |= (1<<17);

    /* PA2 Alternate Function */
    GPIOA_MODER &= ~(3<<4);
    GPIOA_MODER |=  (2<<4);

    /* AF7 */
    GPIOA_AFRL &= ~(0xF<<8);
    GPIOA_AFRL |=  (7<<8);

    /* 115200 baud @16MHz */
    USART2_BRR = 0x008B;

    /* Enable DMA TX */
    USART2_CR3 |= (1<<7);

    /* TE */
    USART2_CR1 |= (1<<3);

    /* UE */
    USART2_CR1 |= (1<<13);
}

void DMA1_Stream6_Init(char *buffer,
                       unsigned int length)
{
    /* DMA1 Clock */
    RCC_AHB1ENR |= (1<<21);

    /* Disable Stream */
    DMA1_S6CR &= ~(1<<0);

    while(DMA1_S6CR & 1);

    /* Clear Flags */
    DMA1_HIFCR = 0x0F400000;

    /* Channel 4 */
    DMA1_S6CR |= (4<<25);

    /* Memory Increment */
    DMA1_S6CR |= (1<<10);

    /* Direction Memory->Peripheral */
    DMA1_S6CR |= (1<<6);

    /* Peripheral Address */
    DMA1_S6PAR = (unsigned int)&USART2_DR;

    /* Memory Address */
    DMA1_S6M0AR = (unsigned int)buffer;

    /* Length */
    DMA1_S6NDTR = length;
}

void UART_DMA_Send(char *buffer,
                   unsigned int length)
{
    DMA1_Stream6_Init(buffer,length);

    DMA1_S6CR |= (1<<0);

    while(!(DMA1_HISR & (1<<21)));

    DMA1_HIFCR = (1<<21);
}
