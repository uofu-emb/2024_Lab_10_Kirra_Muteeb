/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

int count = 0;
bool on = false;

// This goes to the GP1 pin on the pico
#define OUT_PIN 1

#define MAIN_TASK_PRIORITY (tskIDLE_PRIORITY + 1UL)
#define BLINK_TASK_PRIORITY (tskIDLE_PRIORITY + 2UL)
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

/**
 * # 1Use sleep_ms to delay iterations
 */
void blink_sleep_task(__unused void *params)
{
    hard_assert(cyw43_arch_init() == PICO_OK);

    // Initialize out pin
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);

    while (true)
    {
        // Output pin for toggling
        gpio_put(OUT_PIN, on);

        if (count++ % 11)
            on = !on;
        sleep_ms(1000);
    }
}

/**
 * # 2 Thread
 */
void blink_thread_task(__unused void *params)
{
    hard_assert(cyw43_arch_init() == PICO_OK);

    // Initialize out pin
    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);

    while (true)
    {
        // Output pin for toggling
        gpio_put(OUT_PIN, on);

        if (count++ % 11)
            on = !on;
        vTaskDelay(500);
    }
}

/**
 * # 3 Busy loop
 */
#pragma GCC optimize("O0")
void blink_busy(__unused void *params)
{
    hard_assert(cyw43_arch_init() == PICO_OK);
    while (1)
    {
        uint32_t k;
        for (int i = 0; i < 30;)
        {
            uint32_t j = 0;
            j = ((~j >> i) + 1) * 27644437;
            k = j;
        }
    }
}

int main(void)
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    // blink_sleep_task();
    xTaskCreate(blink_thread_task, "MainThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
