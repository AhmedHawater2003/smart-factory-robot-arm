#include "LED_driver.h"

void LED_Init_Positive_Logic (uint8_t led_id)
{
    gpio_init(led_id); //initializing the GPIO pin
    gpio_set_dir(led_id, GPIO_OUT); //setting the direction of the GPIO pin as output
    gpio_put(led_id,0); //setting the initial state of the GPIO pin as low
}

void LED_Init_Negative_Logic (uint8_t led_id)
{
    gpio_init(led_id); //initializing the GPIO pin
    gpio_set_dir(led_id, GPIO_OUT); //setting the direction of the GPIO pin as output
    gpio_put(led_id,1); //setting the initial state of the GPIO pin as high
}

void LED_On(uint8_t led_id , bool positive_logic) //function definition for turning on the LED
{
    if(positive_logic) //if the LED is initialized with positive logic
    {
        gpio_put(led_id, 1); //setting the state of the GPIO pin as high
    }
    else                //if the LED is initialized with negative logic
    {
        gpio_put(led_id, 0); //setting the state of the GPIO pin as low
    }
}


void LED_Off(uint8_t led_id , bool positive_logic) //function definition for turning off the LED
{
    if(positive_logic) //if the LED is initialized with positive logic
    {
        gpio_put(led_id, 0); //setting the state of the GPIO pin as low
    }
    else            //if the LED is initialized with negative logic
    {
        gpio_put(led_id, 1); //setting the state of the GPIO pin as high
    }
}


void LED_Toggle(uint8_t led_id) //function definition for toggling the LED
{
    gpio_put(led_id, !gpio_get(led_id)); //toggling the state of the GPIO pin
}

