#include "monitoring.h"
#include "task.h"
#include "uart_driver.h"
#include <stdio.h>

#define MONITOR_INTERVAL_MS 1000

void monitoring_init(void) {
    xTaskCreate(monitoring_task, "Monitor", configMINIMAL_STACK_SIZE + 64, NULL, 1, NULL);
}

void monitoring_task(void *pvParameters) {
    (void)pvParameters;
    char buffer[128];
    for (;;) {
        UBaseType_t uxTasks;
        TaskStatus_t *pxTaskStatusArray;
        volatile UBaseType_t uxArraySize, x;
        uint32_t ulTotalRunTime;

        uxArraySize = uxTaskGetNumberOfTasks();
        pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );
        uxArraySize = uxTaskGetSystemState( pxTaskStatusArray, uxArraySize, &ulTotalRunTime );

        sprintf(buffer, "Timestamp: %u ms\n", xTaskGetTickCount() * (1000 / configTICK_RATE_HZ));
        uart_send_string(buffer);
        sprintf(buffer, "CPU Load: %lu%%\n", ulTotalRunTime / portTICK_PERIOD_MS);
        uart_send_string(buffer);

        for (x = 0; x < uxArraySize; x++) {
            sprintf(buffer, "Task: %s, StackHighWaterMark: %u\n",
                    pxTaskStatusArray[x].pcTaskName,
                    pxTaskStatusArray[x].usStackHighWaterMark);
            uart_send_string(buffer);
        }

        vPortFree(pxTaskStatusArray);
        vTaskDelay(pdMS_TO_TICKS(MONITOR_INTERVAL_MS));
    }
}