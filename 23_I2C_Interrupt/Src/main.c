#include "lcd_i2c.h"

int main(void)
{
    i2c1_init();

    lcd_init();

    lcd_send_string("i2c_interrupt");

    while(1)
    {

    }
}
