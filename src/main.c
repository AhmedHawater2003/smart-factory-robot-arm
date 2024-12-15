#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

#include "servo.h"
#include "LED_driver.h"
#include "IR_sensor.h"
#include "LCD_driver.h"
#include "metal_detector.h"
#include "ultrasonic.h"

#define GRIPPER_PIN 21
#define BASE_PIN 18
#define ELEVATOR_PIN 19

int isResetted = 0;

void servoGoDown(){
    set_servo_angle(ELEVATOR_PIN,60);
}

void servoGrip(){
    set_servo_angle(GRIPPER_PIN,0);
}

void servoGoUp(){
    set_servo_angle(ELEVATOR_PIN,0);
}

void dropToSuccess(){

    set_servo_angle(BASE_PIN,20);
    sleep_ms(500);
    set_servo_angle(BASE_PIN,40);
    sleep_ms(500);
    set_servo_angle(BASE_PIN,60);
    sleep_ms(500);
    set_servo_angle(GRIPPER_PIN,50);
}

// void dropToFailure(){
//     servo_set_position_bottom(0);
//     sleep_ms(3000);
//     servo_set_position_gripper(20);
//     sleep_ms(2000);
//     servo_set_position_gripper(0);
// }

void reset(){
        set_servo_angle(BASE_PIN,0);
        sleep_ms(500);
        set_servo_angle(ELEVATOR_PIN,0);
        sleep_ms(500);
        set_servo_angle(GRIPPER_PIN,50);
        sleep_ms(500);
}

void vMainTask(void *pvParameters)
{
    while (1)
    {
        if(!isResetted){
            reset();
            isResetted = 1;
        }
        uint64_t distance = getCm();
        if(distance <5){
            isResetted = 0;
            sleep_ms(500);
            servoGoDown();
            sleep_ms(500);
            servoGrip();
            sleep_ms(500);
            servoGoUp();
            sleep_ms(500);

            // bool isRed = ir_sensor_is_red(ir_sensor_read_raw());
            // bool isMetal = is_metal();
            // if(isMetal && isRed){
                dropToSuccess();
            // }
            // else{
            //     dropToFailure();
            // }
            sleep_ms(500);
        }


        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void createTasks()
{
    xTaskCreate(vMainTask, "Main Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
}

  
int main()
{
    stdio_init_all();
    
    init_servo(21);
    init_servo(19);
    init_servo(18);

    // ir_sensor_init();
    ultrasonic_init();
    // metal_detector_init();
    createTasks();


    vTaskStartScheduler();
    sleep_ms(1000);

}


// int main() {
    // stdio_init_all(); // Initialize standard I/O for debugging

    // Initialize the servo
    // init_servo(21);
    // init_servo(19);
    // init_servo(18);

//     // Test the servo with different angles
//     // float angles[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
//     float angles[] = {45, 90};
//     while (true) {
//         set_servo_angle(BASE_PIN,0);
//         sleep_ms(1000);
//         set_servo_angle(ELEVATOR_PIN,0);
//         sleep_ms(1000);



//         for (int i = 0; i <2; i++) {
//             printf("Setting angle to %.1f degrees\n", i);
//             set_servo_angle(BASE_PIN, angles[i]); // Set servo to the specified angle
//             sleep_ms(500); // Wait for the servo to move
//             set_servo_angle(ELEVATOR_PIN, angles[i]); // Set servo to the specified angle
//             sleep_ms(500); // Wait for the servo to move
//         }



//         for (int i = 0; i <91; i++) {
//             printf("Setting angle to %.1f degrees\n", i);
//             set_servo_angle(ELEVATOR_PIN, i); // Set servo to the specified angle
//             sleep_ms(100); // Wait for the servo to move
//         }

//         sleep_ms(1000);
//         set_servo_angle(GRIPPER_PIN,0);
//         sleep_ms(1000);

//         for (int i = 90; i >-1; i--) {
//             printf("Setting angle to %.1f degrees\n",i);
//             set_servo_angle(ELEVATOR_PIN, i); // Set servo to the specified angle
//             sleep_ms(100); // Wait for the servo to move
//         }

//         for (int i = 60; i <121; i++) {
//             printf("Setting angle to %.1f degrees\n", i);
//             set_servo_angle(BASE_PIN, i); // Set servo to the specified angle
//             sleep_ms(100); // Wait for the servo to move
//         }

//         sleep_ms(1000);


//         set_servo_angle(GRIPPER_PIN,50);
//         sleep_ms(1000);


//         for (int i = 120; i >-1; i--) {
//             printf("Setting angle to %.1f degrees\n", i);
//             set_servo_angle(BASE_PIN,i); // Set servo to the specified angle
//             sleep_ms(100); // Wait for the servo to move
//         }
                

//     }

//     return 0;
// }