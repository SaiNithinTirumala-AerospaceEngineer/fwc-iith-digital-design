/*
 * FWC IITH – AVR-GCC (C via AVR-GCC Toolchain, NOT Arduino IDE)
 * GATE Question: Truth-table LED sequencing using AVR-GCC
 * Platform: Arduino Uno (ATmega328P) compiled with avr-gcc + avrdude
 * Toolchain: avr-gcc → avra → avrdude (via Termux/Debian on Android)
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Build: make  (uses Makefile with avr-gcc flags for ATmega328P @ 16MHz)
 * Flash: avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -U flash:w:main.hex
 */

#include <avr/io.h>
#include <util/delay.h>

#define TIME_INTERVAL 1000  /* ms per state */

/* LED 1 = PB2 (D2), LED 2 = PB3 (D3) */
#define LED1 PB2
#define LED2 PB3

int main(void) {
    /* Set LED pins as outputs */
    DDRB |= (1 << LED1) | (1 << LED2);

    while (1) {
        /* State 00 */
        PORTB &= ~((1 << LED1) | (1 << LED2));
        _delay_ms(TIME_INTERVAL);

        /* State 10 */
        PORTB |=  (1 << LED1);
        PORTB &= ~(1 << LED2);
        _delay_ms(TIME_INTERVAL);

        /* State 01 */
        PORTB &= ~(1 << LED1);
        PORTB |=  (1 << LED2);
        _delay_ms(TIME_INTERVAL);

        /* State 11 */
        PORTB |=  (1 << LED1) | (1 << LED2);
        _delay_ms(TIME_INTERVAL);
    }

    return 0;
}
