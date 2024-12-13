
// driver file

//Get readings from ultrasonic sensor


#include "ultrasonic.h"

int timeout = 26100;

void ultrasonic_init(){//uint trigPin, uint echoPin)
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

uint64_t getPulse(){//uint trigPin, uint echoPin)
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    uint64_t width = 0;

    while (gpio_get(ECHO_PIN) == 0) tight_loop_contents();
    absolute_time_t startTime = get_absolute_time();
    while (gpio_get(ECHO_PIN) == 1) 
    {
        width++;
        sleep_us(1);
        if (width > timeout) return 0;
    }
    absolute_time_t endTime = get_absolute_time();
    
    return absolute_time_diff_us(startTime, endTime);
}

uint64_t getCm(){//uint trigPin, uint echoPin)

    uint64_t pulseLength = getPulse(TRIG_PIN, ECHO_PIN);
    return pulseLength / 29 / 2;
}

uint64_t getInch(){//uint trigPin, uint echoPin)
    uint64_t pulseLength = getPulse(TRIG_PIN, ECHO_PIN);
    return (long)pulseLength / 74.f / 2.f;
}
