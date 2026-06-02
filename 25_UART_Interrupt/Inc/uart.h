#ifndef UART_H
#define UART_H

#include "stm32f407xx.h"

void UART2_Init(void);
void UART2_SendChar(char c);
void UART2_SendString(char *str);
void UART2_IRQHandler(void);

#endif
