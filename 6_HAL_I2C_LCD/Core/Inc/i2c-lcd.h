/*
 * i2c-lcd.h
 *
 *  Created on: 17-May-2026
 *      Author: Meena DS
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "stm32f4xx_hal.h"

void lcd_init (void);
void lcd_send_string (char *str);
void lcd_put_cur(int row, int col);
void lcd_clear (void);

#endif /* INC_I2C_LCD_H_ */
