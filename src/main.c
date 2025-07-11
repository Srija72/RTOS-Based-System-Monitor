#include "FreeRTOS.h"
#include "task.h"
#include "monitoring.h"
#include "uart_driver.h"

// Simulated workload task
void workload_task(void *pvParameters) {
    volatile uint32_t i;
    for (;;) {
        for (i = 0; i < 1000000; ++i) {
            __asm volatile("nop");
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void) {
    uart_init();
    xTaskCreate(workload_task, "Workload", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    monitoring_init();
    vTaskStartScheduler();
    while (1) {}
    return 0;
}