add_executable(${ProjectName}
    main.c
)

target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${ProjectName} PRIVATE
    pico_stdlib
    pico_stdio
    hardware_i2c
    hardware_pwm
    hardware_adc
    hardware_clocks
    hardware_irq
    hardware_gpio
    FreeRTOS-Kernel-Heap4 
    Servo
    Ultrasonic
    MetalDetector
    LED
    LCD
    IR
    )

pico_add_extra_outputs(${ProjectName})