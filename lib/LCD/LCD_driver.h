#ifndef LCD_DRIVER_H
#define LCD_DRIVER_H


#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef PICO_STDLIB_H
#define PICO_STDLIB_H
#include "pico/stdlib.h"
#endif

#ifndef HARDWARE_I2C_H
#define HARDWARE_I2C_H
#include "hardware/i2c.h"
#endif

#ifndef PICO_BINARY_INFO_H
#define PICO_BINARY_INFO_H
#include "pico/binary_info.h"
#endif

//I2C0 is used here 
//We use GPIO 4 found on pin 6 and GPIO 5 found on pin 7
#ifndef LCD_SDA_GPIO_PIN
#define LCD_SDA_GPIO_PIN 4
#endif

#ifndef LCD_SCL_GPIO_PIN
#define LCD_SCL_GPIO_PIN 5
#endif

#ifndef LCD_CLEARDISPLAY
#define LCD_CLEARDISPLAY        0x01
#endif

#ifndef LCD_RETURNHOME
#define LCD_RETURNHOME          0x02
#endif

#ifndef LCD_ENTRYMODESET
#define LCD_ENTRYMODESET        0x04
#endif

#ifndef LCD_DISPLAYCONTROL
#define LCD_DISPLAYCONTROL      0x08
#endif

#ifndef LCD_CURSORSHIFT
#define LCD_CURSORSHIFT         0x10
#endif

#ifndef LCD_FUNCTIONSET
#define LCD_FUNCTIONSET         0x20
#endif

#ifndef LCD_SETCGRAMADDR
#define LCD_SETCGRAMADDR        0x40
#endif

#ifndef LCD_SETDDRAMADDR
#define LCD_SETDDRAMADDR        0x80
#endif

// flags for display entry mode
#ifndef LCD_ENTRYSHIFTINCREMENT
#define LCD_ENTRYSHIFTINCREMENT 0x01
#endif

#ifndef LCD_ENTRYLEFT
#define LCD_ENTRYLEFT           0x02
#endif

// flags for display and cursor control
#ifndef LCD_BLINKON
#define LCD_BLINKON             0x01
#endif

#ifndef LCD_CURSORON
#define LCD_CURSORON            0x02
#endif

#ifndef LCD_DISPLAYON
#define LCD_DISPLAYON           0x04
#endif

// flags for display and cursor shift
#ifndef LCD_MOVERIGHT
#define LCD_MOVERIGHT           0x04
#endif

#ifndef LCD_DISPLAYMOVE
#define LCD_DISPLAYMOVE         0x08
#endif

// flags for function set
#ifndef LCD_5x10DOTS
#define LCD_5x10DOTS            0x04
#endif

#ifndef LCD_2LINE
#define LCD_2LINE               0x08
#endif

#ifndef LCD_8BITMODE
#define LCD_8BITMODE            0x10
#endif

// flag for backlight control
#ifndef LCD_BACKLIGHT
#define LCD_BACKLIGHT           0x08
#endif

#ifndef LCD_ENABLE_BIT
#define LCD_ENABLE_BIT          0x04
#endif

// Default LCD I2C address
#ifndef LCD_DEFAULT_ADDR
#define LCD_DEFAULT_ADDR        0x27
#endif

// Modes for lcd_send_byte
#ifndef LCD_CHARACTER
#define LCD_CHARACTER           1
#endif

#ifndef LCD_COMMAND
#define LCD_COMMAND             0
#endif

#ifndef MAX_LINES
#define MAX_LINES               2
#endif

#ifndef MAX_CHARS
#define MAX_CHARS               16
#endif

#ifndef DELAY_US
#define DELAY_US                600
#endif

// Quick helper function for single byte transfers
void i2c_write_byte(uint8_t val);
void lcd_toggle_enable(uint8_t val);
void lcd_send_byte(uint8_t val, int mode);
void lcd_clear(void);
void lcd_set_cursor(int line, int position);
static inline void lcd_char(char val);
void lcd_string(const char *s);
void lcd_init(void);

#endif