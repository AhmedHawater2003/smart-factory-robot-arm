

add_library(Servo
Servo/servo.c)

target_link_libraries(Servo PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
)


target_include_directories (Servo INTERFACE
${CMAKE_CURRENT_LIST_DIR}/Servo
)


add_library(Ultrasonic
Ultrasonic/ultrasonic.c)

target_link_libraries(Ultrasonic PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
hardware_adc
)

target_include_directories (Ultrasonic INTERFACE
${CMAKE_CURRENT_LIST_DIR}/Ultrasonic
)


add_library(MetalDetector
MetalDetector/metal_detector.c)

target_link_libraries(MetalDetector PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
)

target_include_directories (MetalDetector INTERFACE
${CMAKE_CURRENT_LIST_DIR}/MetalDetector
)

add_library(LED
LED/LED_driver.c)

target_link_libraries(LED PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
)

target_include_directories (LED INTERFACE
${CMAKE_CURRENT_LIST_DIR}/LED
)

add_library(LCD
LCD/LCD_driver.c)

target_link_libraries(LCD PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
hardware_i2c
)

target_include_directories (LCD INTERFACE
${CMAKE_CURRENT_LIST_DIR}/LCD
)

add_library(IR
IR/IR_sensor.c)

target_link_libraries(IR PRIVATE
pico_stdlib
pico_stdio
hardware_pwm
hardware_clocks
hardware_irq
hardware_gpio
hardware_adc
)

target_include_directories (IR INTERFACE
${CMAKE_CURRENT_LIST_DIR}/IR
)