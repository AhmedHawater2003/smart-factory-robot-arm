#ifndef LED_DRIVER_H  //to ensure that no other header file has the same name
#define LED_DRIVER_H

#ifndef STDINT_H //to ensure that no other file has already included this library
#define STDINT_H
#include <stdint.h>
#endif


#ifndef PICO_STDLIB_H //to ensure that no other file has already included this library
#define PICO_STDLIB_H
#include "pico/stdlib.h"
#endif

#define LED_RED 14 //defining the pin number for the Red Led to be Pin 18
#define LED_GREEN 15 //defining the pin number for the Green Led to be Pin 19
#define LED_BLUE 20 //defining the pin number for the Blue Led to be Pin 20
#define LED_Initial_Delay 5e3  //5 seconds
#define LED_Alternating_Delay 1e3 // 1 second

void LED_Init_Positive_Logic (uint8_t led_id); //function declaration for initializing the LED with positive logic
void LED_Init_Negative_Logic (uint8_t led_id); //function declaration for initializing the LED with negative logic
void LED_On(uint8_t led_id , bool positive_logic); //function declaration for turning on the LED
void LED_Off(uint8_t led_id , bool positive_logic); //function declaration for turning off the LED
void LED_Toggle(uint8_t led_id); //function declaration for toggling the LED


#endif