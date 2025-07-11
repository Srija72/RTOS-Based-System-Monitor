# FreeRTOS System Monitoring Tool

This project demonstrates a real-time system monitoring tool using FreeRTOS. It tracks task states, CPU load, and stack usage in real time and reports data over UART.

## Features

- Monitors and logs:
  - **Timestamp**
  - **CPU Load (%)**
  - **Task stack high water marks**
- Simulates workloads with a periodic busy-wait task
- Reports metrics over UART (redirected to console in simulation)

## Building

```bash
make
```

## Running

Load `freertos_monitor.elf` on your Cortex-M microcontroller or simulator.

## Sample Output

![CPU Load Over Time](/mnt/data/cpu_load.png)
![Stack Usage Over Time](/mnt/data/stack_usage.png)

## File Structure

```
freertos_monitor/
├── include/
│   ├── FreeRTOSConfig.h
│   ├── monitoring.h
│   └── uart_driver.h
├── src/
│   ├── main.c
│   ├── monitoring.c
│   └── uart_driver.c
└── Makefile
```

## License

MIT License


