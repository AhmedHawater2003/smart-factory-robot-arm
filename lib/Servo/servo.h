#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif

#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Servo configuration constants
#define PWM_FREQ 50            // Servo PWM frequency (50 Hz)
#define MIN_DUTY_US 500        // Minimum pulse width in microseconds (2.5% duty cycle)
#define MAX_DUTY_US 2500       // Maximum pulse width in microseconds (12.5% duty cycle)

// Function prototypes

/**
 * @brief Initializes the servo control on the specified GPIO pin.
 * 
 * @param gpio_pin The GPIO pin connected to the servo signal.
 */
void init_servo(uint gpio_pin);

/**
 * @brief Sets the servo to a specific angle (0° to 180°).
 * 
 * @param gpio_pin The GPIO pin connected to the servo signal.
 * @param angle The desired servo angle in degrees (0° to 180°).
 */
void set_servo_angle(uint gpio_pin, float angle);

/**
 * @brief Converts the desired servo angle to the corresponding PWM duty cycle.
 * 
 * @param angle The desired servo angle in degrees (0° to 180°).
 * @return uint16_t The corresponding PWM duty cycle as a 16-bit value.
 */
uint16_t angle_to_duty(float angle);

#endif // SERVO_CONTROL_H