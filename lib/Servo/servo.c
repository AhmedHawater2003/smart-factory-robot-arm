#include "servo.h"

// Define the GPIO pin connected to the servo signal
#define SERVO_PIN 5 // Use the GPIO pin you have connected the servo to

#define PWM_FREQ 50            // PWM frequency for the servo (50 Hz)
#define MIN_DUTY_US 500        // Minimum duty cycle in microseconds (2.5%)
#define MAX_DUTY_US 2500       // Maximum duty cycle in microseconds (12.5%)

// Function to calculate the PWM duty cycle for a given angle
uint16_t angle_to_duty(float angle) {
    // Ensure angle is clamped between 0° and 180°
    if (angle < 0.0f) angle = 0.0f;
    if (angle > 180.0f) angle = 180.0f;

    // Convert angle to duty in microseconds
    float duty_us = MIN_DUTY_US + (angle / 180.0f) * (MAX_DUTY_US - MIN_DUTY_US);

    // Convert duty in microseconds to a 16-bit PWM level
    uint32_t pwm_wrap = 1250000 / PWM_FREQ; // Wrap value for the desired frequency
    return (uint16_t)((duty_us / 20000.0f) * pwm_wrap);
}

// Function to initialize the PWM for the servo
void init_servo(uint gpio_pin) {
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM); // Set GPIO pin to PWM mode
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin); // Get the PWM slice
    uint channel = pwm_gpio_to_channel(gpio_pin); // Get the PWM channel

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f); // Set clock divider for 50 Hz frequency
    pwm_init(slice_num, &config, true); // Initialize PWM with the given config
}

// Function to set the servo angle
void set_servo_angle(uint gpio_pin, float angle) {
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin); // Get the PWM slice
    uint16_t duty = angle_to_duty(angle); // Convert angle to duty cycle
    pwm_set_gpio_level(gpio_pin, duty); // Set the PWM duty cycle
}