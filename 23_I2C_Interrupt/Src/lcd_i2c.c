#include "lcd_i2c.h"

void delay(void)
{
    for(volatile int i=0;i<50000;i++);
}

void lcd_write(char data)
{
    i2c1_master_write_interrupt(data | 0x0C);
    delay();

    i2c1_master_write_interrupt(data | 0x08);
    delay();
}

void lcd_send_cmd(char cmd)
{
    char upper, lower;

    upper = cmd & 0xF0;
    lower = (cmd << 4) & 0xF0;

    lcd_write(upper);
    lcd_write(lower);
}

void lcd_send_data(char data)
{
    char upper, lower;

    upper = data & 0xF0;
    lower = (data << 4) & 0xF0;

    lcd_write(upper | 1);
    lcd_write(lower | 1);
}

void lcd_send_string(char *str)
{
    while(*str)
    {
        lcd_send_data(*str++);
    }
}

void lcd_init(void)
{
    delay();

    lcd_send_cmd(0x02);
    lcd_send_cmd(0x28);
    lcd_send_cmd(0x0C);
    lcd_send_cmd(0x06);
    lcd_send_cmd(0x01);

    delay();
}
