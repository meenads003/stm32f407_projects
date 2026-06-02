/*
 * uart_dma.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */

#ifndef UART_DMA_H
#define UART_DMA_H

void UART2_Init(void);
void DMA1_Stream6_Init(char *buffer,
                       unsigned int length);

void UART_DMA_Send(char *buffer,
                   unsigned int length);

void delay_ms(unsigned int ms);

#endif
