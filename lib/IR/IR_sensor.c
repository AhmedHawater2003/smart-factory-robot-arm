#include "IR_sensor.h"


// Initialize the ADC for the IR sensor
void ir_sensor_init() {
    adc_init(); // Initialize the ADC hardware
    adc_gpio_init(IR_SENSOR_ADC_PIN); // Initialize the specific GPIO pin for ADC
    adc_select_input(IR_SENSOR_ADC_PIN - 26); // Select the ADC input channel (0-2 for GP26-GP28)
}

// Read the raw ADC value from the IR sensor
uint16_t ir_sensor_read_raw(void) {
    return adc_read(); // Read and return the raw 12-bit ADC value
}

// Convert raw ADC value to distance (optional, depends on sensor type)
float ir_sensor_get_distance(uint16_t raw_value) {
    // Conversion logic specific to your IR sensor
    // Example: For a linear voltage-distance relation
    float voltage = (raw_value / 4095.0f) * 3.3f; // Convert raw value to voltage
    float distance = 100.0f / voltage; // Example: Placeholder formula
    return distance;
}

bool ir_sensor_is_red(uint16_t raw_value) {
    // Define thresholds based on your experiment
    const uint16_t red_min_threshold = 1500; // Example minimum raw value for red
    const uint16_t red_max_threshold = 2500; // Example maximum raw value for red

    // Check if the raw value falls within the range for red objects
    return (raw_value >= red_min_threshold && raw_value <= red_max_threshold);
}

bool is_black(){
    uint16_t raw_value = ir_sensor_read_raw();
    return raw_value > 2000;
}