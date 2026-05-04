# AVR-GCC — Bare-Metal C (No Arduino IDE)

**Platform:** Arduino Uno (ATmega328P)  
**Problem:** LED truth-table sequencing using direct register access  
**Toolchain:** avr-gcc + avr-objcopy (Makefile) → ArduinoDroid

## Build
```bash
# Inside Termux Debian:
cd src/
make        # produces main.hex
# Flash via ArduinoDroid → Actions → Upload → Upload Precompiled → main.hex
```

## Key Difference from Arduino
No `digitalWrite()` — uses direct register manipulation:
```c
DDRB  |= (1 << LED1);         // set direction
PORTB |= (1 << LED1);         // set HIGH
PORTB &= ~(1 << LED1);        // set LOW
_delay_ms(TIME_INTERVAL);     // hardware delay
```
