#include "uart_driver.h"
#include <stdio.h>
#include <stdarg.h>

void uart_init(void) {
    // Initialize UART hardware here
}

void uart_send_string(const char *str) {
    // Send string over UART
    printf("%s", str); // For simulation
}