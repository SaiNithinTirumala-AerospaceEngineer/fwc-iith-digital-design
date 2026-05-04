/*
 * FWC IITH – AVR-GCC Two-LED Variant (Dual LED State Sequencer)
 * GATE Task: Display 2-bit binary state sequence (00,10,01,11) using 2 LEDs
 * Platform : Arduino Uno (ATmega328P) — bare-metal, NO Arduino IDE
 * Toolchain: avr-gcc + avr-objcopy → Makefile → ArduinoDroid upload
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * LED1 = PB2 (D2), LED2 = PB3 (D3)
 * Sequence cycles: 00 → 10 → 01 → 11 → 00 ... (1 second each)
 * Direct DDRB/PORTB register access — no Arduino HAL
 */

AVR-GCC Code:
#include <avr/io.h>
#include <util/delay.h>

// Define the pins for the LEDs
#define LED_PIN1 PB2 // Digital pin 2 for LED 1
#define LED_PIN2 PB3 // Digital pin 3 for LED 2

int main(void) {
    // Set pins as output
    DDRB |= (1 << LED_PIN1) | (1 << LED_PIN2);

    while (1) {
        // Sequence: 00
        PORTB &= ~((1 << LED_PIN1) | (1 << LED_PIN2));
        _delay_ms(1000); // 1 second delay

        // Sequence: 10
        PORTB |= (1 << LED_PIN1);
        PORTB &= ~(1 << LED_PIN2);
        _delay_ms(1000); // 1 second delay

        // Sequence: 01
        PORTB &= ~(1 << LED_PIN1);
        PORTB |= (1 << LED_PIN2);
        _delay_ms(1000); // 1 second delay

        // Sequence: 11
        PORTB |= (1 << LED_PIN1) | (1 << LED_PIN2);
        _delay_ms(1000); // 1 second delay

        // Sequence: 00 (Reset)
        PORTB &= ~((1 << LED_PIN1) | (1 << LED_PIN2));
        _delay_ms(1000); // 1 second delay
    }

    return 0;
}