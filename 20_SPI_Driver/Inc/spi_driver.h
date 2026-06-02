#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <stdint.h>

void spi1_init(void);
void spi1_transmit(uint8_t data);

#endif
