# AVR-GCC Makefile – ATmega328P @ 16 MHz
MCU     = atmega328p
F_CPU   = 16000000UL
CC      = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS  = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -std=c99

all: main.hex

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

main.elf: main.o
	$(CC) $(CFLAGS) -o $@ $<

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f *.o *.elf *.hex
