#ifndef LCD_I2C_H_
#define LCD_I2C_H_

#include "i2c_driver.h"

#define SLAVE_ADDRESS_LCD 0x7E

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_set_cursor(int row, int col);

#endif
