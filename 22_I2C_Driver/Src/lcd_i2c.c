#include "lcd_i2c.h"
#include <stdint.h>

void delay(void)
{
    for(volatile int i=0; i<50000; i++);
}
void lcd_write_nibble(char nibble, char rs)
{
    char data_t;

    data_t = nibble | rs;

    i2c1_start();

    i2c1_write_address(SLAVE_ADDRESS_LCD);

    i2c1_write_data(data_t | 0x0C);

    delay();

    i2c1_write_data(data_t | 0x08);

    delay();

    i2c1_stop();
}

void lcd_send_cmd(char cmd)
{
    char upper, lower;

    upper = cmd & 0xF0;
    lower = (cmd << 4) & 0xF0;

    lcd_write_nibble(upper, 0);
    lcd_write_nibble(lower, 0);
}

void lcd_send_data(char data)
{
    char upper, lower;

    upper = data & 0xF0;
    lower = (data << 4) & 0xF0;

    lcd_write_nibble(upper, 1);
    lcd_write_nibble(lower, 1);
}

void lcd_send_string(char *str)
{
    while(*str)
    {
        lcd_send_data(*str++);
    }
}

void lcd_set_cursor(int row, int col)
{
    uint8_t address;

    if(row == 0)
        address = 0x80 + col;
    else
        address = 0xC0 + col;

    lcd_send_cmd(address);
}

void lcd_init(void)
{
    delay();

    lcd_send_cmd(0x02);
    lcd_send_cmd(0x28);
    lcd_send_cmd(0x0C);
    lcd_send_cmd(0x06);
    lcd_send_cmd(0x01);

    for(volatile int i=0; i<200000; i++);
}
