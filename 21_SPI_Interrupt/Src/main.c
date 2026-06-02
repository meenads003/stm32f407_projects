#include "lcd_i2c.h"

int main(void)
{
    i2c1_init();
    lcd_init();

    lcd_set_cursor(0,0);
    lcd_send_string("Hello Meena");

    lcd_set_cursor(1,0);
    lcd_send_string("STM32 I2C Bare");

    while (1)
    {
        // no delay, no HAL
    }
}
