#include "servo.h"

/**
 * Disables the PWM (Pulse Width Modulation) signal for the servo motor.
 *
 * @return uint64_t Always returns 0.
 */
uint64_t servo_disable()
{
    // Get the PWM slice number associated with the servo pin
    const uint8_t slice = pwm_gpio_to_slice_num(SERVO_PIN);

    // Disable PWM output for the slice
    pwm_set_enabled(slice, false);

    // Return 0 to indicate success
    return 0;
}

/**
 * Enables and configures the PWM signal for the servo motor to operate at a 50 Hz frequency.
 *
 * @return uint64_t
 *         0: Success
 *         1: Frequency is too low
 *         2: Frequency is too high
 */
uint64_t servo_enable()
{
    // Configure the GPIO pin connected to the servo for PWM function
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

    // Get the PWM slice number for the servo pin
    const uint8_t slice = pwm_gpio_to_slice_num(SERVO_PIN);

    // Target frequency for the servo (50 Hz for a 20 ms PWM period)
    const uint freq = 50;

    // Retrieve the clock frequency of the system clock (clk_sys)
    uint32_t source_hz = clock_get_hz(clk_sys);

    // Calculate the division factor and top value for achieving the target frequency
    uint32_t div16_top = 16 * source_hz / freq;
    uint32_t top = 1;

    // Optimize the division factor and top value by reducing div16_top while keeping top within limits
    for (;;) {
        // Attempt to divide div16_top by small prime factors while keeping top within limits
        if (div16_top >= 16 * 5 && div16_top % 5 == 0 && top * 5 <= SERVO_TOP_MAX) {
            div16_top /= 5;
            top *= 5;
        } else if (div16_top >= 16 * 3 && div16_top % 3 == 0 && top * 3 <= SERVO_TOP_MAX) {
            div16_top /= 3;
            top *= 3;
        } else if (div16_top >= 16 * 2 && top * 2 <= SERVO_TOP_MAX) {
            div16_top /= 2;
            top *= 2;
        } else {
            break; // Exit the loop if no further reduction is possible
        }
    }

    // Check if the calculated division factor is within valid range
    if (div16_top < 16) {
        return 2; // Frequency is too high
    } else if (div16_top >= 256 * 16) {
        return 1; // Frequency is too low
    }

    // Set the division factor and top value for the PWM slice
    pwm_hw->slice[slice].div = div16_top;
    pwm_hw->slice[slice].top = top;

    // Return 0 to indicate successful configuration
    return 0;
}

/**
 * Sets the position of the servo motor by adjusting the PWM duty cycle.
 *
 * @param degree: The desired position of the servo in degrees (0-180).
 *                Values outside this range are adjusted using modulo operation.
 *
 * @return uint64_t Always returns 0 to indicate success.
 */
uint64_t servo_set_position(const uint16_t degree)
{
    // Calculate the pulse width corresponding to a 1 ms pulse (5% duty cycle)
    const uint16_t oneMs = SERVO_TOP_MAX / 20;

    // Calculate the duty cycle for the desired degree position
    // Degree is converted to a pulse width between 1 ms (0 degrees) and 2 ms (180 degrees)
    const uint16_t duty_u16 = oneMs + (oneMs * degree) / 180;

    // Get the PWM slice and channel numbers associated with the servo pin
    const uint8_t slice = pwm_gpio_to_slice_num(SERVO_PIN);
    const uint8_t channel = pwm_gpio_to_channel(SERVO_PIN);

    // Get the top value for the configured PWM slice
    const uint32_t top = pwm_hw->slice[slice].top;

    // Calculate the compare value for the PWM signal (scaled duty cycle)
    const uint32_t cc = duty_u16 * (top + 1) / SERVO_TOP_MAX;

    // Set the PWM compare level to adjust the duty cycle for the servo
    pwm_set_chan_level(slice, channel, cc);

    // Enable the PWM output for the slice
    pwm_set_enabled(slice, true);

    // Return 0 to indicate success
    return 0;
}
