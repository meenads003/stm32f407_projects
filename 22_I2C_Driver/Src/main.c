#include "lcd_i2c.h"

int main(void)
{
    i2c1_init();

    lcd_init();

    lcd_set_cursor(0,0);
    lcd_send_string("i2c_driver");

    lcd_set_cursor(1,0);
    lcd_send_string("_Baremetal");

    while(1)
    {

    }
}
