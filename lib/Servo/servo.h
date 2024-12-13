#ifndef SERVO_H
#define SERVO_H

#ifndef PICO_STDIO_H // Ensure no duplicate inclusion of pico/stdio.h
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#ifndef PICO_STDLIB_H // Ensure no duplicate inclusion of pico/stdlib.h
#define PICO_STDLIB_H
#include "pico/stdlib.h"
#endif

#ifndef STDIO_H // Ensure no duplicate inclusion of stdio.h
#define STDIO_H
#include <stdio.h>
#endif


#ifndef HARDWARE_CLOCKS_H // Ensure no duplicate inclusion of hardware/clocks.h
#define HARDWARE_CLOCKS_H
#include "hardware/clocks.h"
#endif

#ifndef HARDWARE_GPIO_H // Ensure no duplicate inclusion of hardware/gpio.h
#define HARDWARE_GPIO_H
#include "hardware/gpio.h"
#endif

#ifndef HARDWARE_IRQ_H // Ensure no duplicate inclusion of hardware/irq.h
#define HARDWARE_IRQ_H
#include "hardware/irq.h"
#endif

#ifndef HARDWARE_PWM_H // Ensure no duplicate inclusion of hardware/pwm.h
#define HARDWARE_PWM_H
#include "hardware/pwm.h"
#endif

// Set the frequency, making "top" as large as possible for maximum resolution.
// Maximum "top" is set at 65534 to be able to achieve 100% duty with 65535.
#ifndef SERVO_TOP_MAX
#define SERVO_TOP_MAX 65534
#endif

// Pre-defined GPIO pin for the servo
#ifndef SERVO_PIN
#define SERVO_PIN 21
#endif


uint64_t servo_enable();

uint64_t servo_disable();

/**
 * Sets the position of the servo using the the duty cycle of the PWM signal.
 *
 * @param degree: the position in degree, the value is then %181 (within 0 and 180).
 * **/
uint64_t servo_set_position(const uint16_t degree);

#endif