#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stdint.h>

void uart_init(void);
void uart_send_string(const char *str);

#endif // UART_DRIVER_H