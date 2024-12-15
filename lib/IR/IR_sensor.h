#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#ifndef PICO_STDIO_H
#define PICO_STDIO_H
#include "pico/stdio.h"
#endif

#ifndef PICO_STDLIB_H
#define PICO_STDLIB_H
#include "pico/stdlib.h"
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif

#ifndef HARDWARE_ADC_H
#define HARDWARE_ADC_H
#include "hardware/adc.h"
#endif

#ifndef PICO_TIME_H
#define PICO_TIME_H
#include "pico/time.h"
#endif



#define IR_SENSOR_ADC_PIN 28 // Example: GP26

// Function to initialize the ADC for the IR sensor
void ir_sensor_init();

// Function to read the analog value from the IR sensor
uint16_t ir_sensor_read_raw(void);

// Function to get a distance or detection value (if applicable)
float ir_sensor_get_distance(uint16_t raw_value);

// Function to classify if the object is red based on the ADC value
bool ir_sensor_is_red(uint16_t raw_value);

bool is_black(void);

#endif