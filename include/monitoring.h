#ifndef MONITORING_H
#define MONITORING_H

#include "FreeRTOS.h"

void monitoring_init(void);
void monitoring_task(void *pvParameters);

#endif // MONITORING_H