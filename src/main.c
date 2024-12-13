#include "FreeRTOS.h"
#include "task.h"
#include "servo.h"
#include "LED_driver.h"
#include "IR_sensor.h"
#include "LCD_driver.h"
#include "metal_detector.h"
#include "ultrasonic.h"
#include <stdio.h>
#include "pico/stdlib.h"


int main()
{
    stdio_init_all();

    // xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    // vTaskStartScheduler();
    sleep_ms(2000);

    printf("This line should never be printed\n");

}

// Note: Ensure that the program name is correctly specified in the launch configuration.