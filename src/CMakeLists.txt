# This is the main binary. List your C files here.
add_executable(power
    power.c
)

add_executable(hello_sleep_alarm
    hello_sleep_alarm.c
)

target_link_libraries(hello_sleep_alarm
    pico_stdlib
    hardware_sleep
)

add_executable(hello_dormant_gpio
    hello_dormant_gpio.c
)

target_link_libraries(hello_dormant_gpio
    pico_stdlib
    hardware_sleep
)

pico_set_program_name(power "test")
pico_set_program_version(power "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(power 0)
pico_enable_stdio_usb(power 1)

# Add the libraries to the build
target_link_libraries(power PRIVATE
    pico_stdlib
    pico_multicore
    pico_async_context_freertos
    FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(power PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(power)
pico_add_extra_outputs(hello_sleep_alarm)
pico_add_extra_outputs(hello_dormant_gpio)

add_custom_target(flash picotool load -f $<TARGET_FILE:power> DEPENDS power)
