/*
 * lcd_i2c.c
 *
 *  Created on: Jun 1, 2026
 *      Author: Meena DS
 */


#include "lcd_i2c.h"

/*
PCF8574 Mapping

P0 -> RS
P1 -> RW
P2 -> EN
P3 -> Backlight

P4 -> D4
P5 -> D5
P6 -> D6
P7 -> D7
*/

#define LCD_ADDR 0x3F

#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE    0x04
#define LCD_RS        0x01

static void LCD_Write4Bits(unsigned char data);
static void LCD_PulseEnable(unsigned char data);

/**********************************************************
 * Generate Enable Pulse
 **********************************************************/
static void LCD_PulseEnable(unsigned char data)
{
    I2C1_Write(LCD_ADDR,
               data | LCD_ENABLE);

    delay_ms(1);

    I2C1_Write(LCD_ADDR,
               data & ~LCD_ENABLE);

    delay_ms(1);
}

/**********************************************************
 * Write 4-bit nibble
 **********************************************************/
static void LCD_Write4Bits(unsigned char data)
{
    I2C1_Write(LCD_ADDR, data);

    LCD_PulseEnable(data);
}

/**********************************************************
 * Send Command
 **********************************************************/
void LCD_SendCmd(unsigned char cmd)
{
    unsigned char highNibble;
    unsigned char lowNibble;

    highNibble = cmd & 0xF0;

    lowNibble = (cmd << 4) & 0xF0;

    LCD_Write4Bits(highNibble | LCD_BACKLIGHT);

    LCD_Write4Bits(lowNibble | LCD_BACKLIGHT);

    delay_ms(2);
}

/**********************************************************
 * Send Data
 **********************************************************/
void LCD_SendData(unsigned char data)
{
    unsigned char highNibble;
    unsigned char lowNibble;

    highNibble = data & 0xF0;

    lowNibble = (data << 4) & 0xF0;

    LCD_Write4Bits(highNibble |
                   LCD_RS |
                   LCD_BACKLIGHT);

    LCD_Write4Bits(lowNibble |
                   LCD_RS |
                   LCD_BACKLIGHT);

    delay_ms(2);
}

/**********************************************************
 * Send String
 **********************************************************/
void LCD_SendString(char *str)
{
    while(*str)
    {
        LCD_SendData(*str);
        str++;
    }
}

/**********************************************************
 * Clear LCD
 **********************************************************/
void LCD_Clear(void)
{
    LCD_SendCmd(0x01);

    delay_ms(5);
}

/**********************************************************
 * Cursor Position
 **********************************************************/
void LCD_SetCursor(unsigned char row,
                   unsigned char col)
{
    unsigned char address;

    if(row == 0)
    {
        address = 0x80 + col;
    }
    else
    {
        address = 0xC0 + col;
    }

    LCD_SendCmd(address);
}

/**********************************************************
 * LCD Initialization
 **********************************************************/
void LCD_Init(void)
{
    delay_ms(50);

    LCD_Write4Bits(0x30);
    delay_ms(5);

    LCD_Write4Bits(0x30);
    delay_ms(5);

    LCD_Write4Bits(0x30);
    delay_ms(5);

    LCD_Write4Bits(0x20);
    delay_ms(5);

    /* 4-bit mode */
    LCD_SendCmd(0x28);

    /* Display ON */
    LCD_SendCmd(0x0C);

    /* Entry mode */
    LCD_SendCmd(0x06);

    /* Clear */
    LCD_SendCmd(0x01);

    delay_ms(5);
}
