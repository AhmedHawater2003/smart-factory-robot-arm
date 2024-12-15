// header file

#ifndef ultrasonic_h
#define ultrasonic_h

#ifndef PICO_STDLIB_H //to ensure that no other file has already included this library
#define PICO_STDLIB_H
#include "pico/stdlib.h"
#endif

#ifndef STDINT_H //to ensure that no other file has already included this library
#define STDINT_H
#include <stdint.h>
#endif

#ifndef HARDWARE_GPIO_H
#define HARDWARE_GPIO_H
#include "hardware/gpio.h"
#endif

#ifndef HARDWARE_TIMER_H
#define HARDWARE_TIMER_H
#include "hardware/timer.h"
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef ECHO_PIN
#define ECHO_PIN 26
#endif

#ifndef TRIG_PIN
#define TRIG_PIN 27
#endif


void ultrasonic_init();//uint trigPin, uint echoPin);
uint64_t getCm();//uint trigPin, uint echoPin);
uint64_t getInch();//uint trigPin, uint echoPin);
#endif
