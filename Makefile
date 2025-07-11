CC=arm-none-eabi-gcc
CFLAGS=-Iinclude -O2 -mcpu=cortex-m3 -mthumb
LDFLAGS=-T linkerscript.ld
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
TARGET=freertos_monitor.elf

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)