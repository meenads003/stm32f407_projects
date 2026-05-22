/*
 * lcd_i2c.h
 *
 *  Created on: 17-May-2026
 *      Author: Meena DS
 */


#ifndef INC_LCD_I2C_H_
#define INC_LCD_I2C_H_

#include "main.h"

void lcd_init(void);
void lcd_send_string(char *str);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_put_cur(int row, int col);
void lcd_clear(void);

#endif /* INC_LCD_I2C_H_ */
