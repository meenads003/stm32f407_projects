#include <stdint.h>
#include "spi_driver.h"

volatile uint8_t tx_data = 0x41;

int main(void)
{
    spi1_init();

    while (1)
    {
        spi1_transmit(tx_data);

        for (volatile int i = 0; i < 1000000; i++);
    }
}
