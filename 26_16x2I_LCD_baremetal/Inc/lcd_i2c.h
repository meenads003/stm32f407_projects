/*
 * lcd_i2c.h
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */

#ifndef LCD_I2C_H
#define LCD_I2C_H

#include "i2c_driver.h"

/* LCD Functions */
void LCD_Init(void);
void LCD_SendCmd(unsigned char cmd);
void LCD_SendData(unsigned char data);
void LCD_SendString(char *str);
void LCD_Clear(void);
void LCD_SetCursor(unsigned char row,
                   unsigned char col);

#endif
