#ifndef METAL_DETECTOR_H
#define METAL_DETECTOR_H

#ifndef HARDWARE_GPIO_H // Ensure no duplicate inclusion of hardware/gpio.h
#define HARDWARE_GPIO_H
#include "hardware/gpio.h"
#endif

// Metal Detector specific constants
#ifndef METAL_DETECTOR_PIN
#define METAL_DETECTOR_PIN 0
#endif

// Metal Detector function prototypes

/**
 * Initialize the metal detector sensor.
 *
 * @param gpio_pin: The GPIO pin connected to the sensor.
 * @return 0 if initialization was successful, non-zero otherwise.
 **/
uint64_t metal_detector_init();

/**
 * Read the state of the metal detector sensor.
 *
 * @param gpio_pin: The GPIO pin connected to the sensor.
 * @return 1 if metal is detected, 0 otherwise.
 **/
uint64_t metal_detector_read();

bool is_metal();

#endif // METAL_DETECTOR_H
