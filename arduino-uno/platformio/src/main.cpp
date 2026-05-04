/*
 * FWC IITH – PlatformIO Framework (AVR C++ via PlatformIO CLI)
 * GATE Question: Boolean function F(A,B,C) = BC + A'C' evaluated on Arduino Uno
 * Platform: Arduino Uno | Framework: PlatformIO (NOT Arduino IDE)
 * Build: pio run  |  Flash: pio run -t upload
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 */

#include <Arduino.h>

const int pinA = A0;   // Input A (analog pin used as digital)
const int pinB = A1;   // Input B
const int pinC = A2;   // Input C
const int pinZ = 13;   // Output LED

void setup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinZ, OUTPUT);
}

void loop() {
  bool a = digitalRead(pinA);
  bool b = digitalRead(pinB);
  bool c = digitalRead(pinC);

  // F(A,B,C) = (B && C) || (!A && !C)
  bool z = (b && c) || (!a);

  digitalWrite(pinZ, z);
  delay(100);
}
