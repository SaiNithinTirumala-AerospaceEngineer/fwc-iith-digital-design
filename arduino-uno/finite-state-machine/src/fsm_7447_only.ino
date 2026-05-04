/*
 * FWC IITH – FSM Variant 2: Using Only 7447 IC (No 7474)
 * GATE Task: FSM state counter using 7447 decoder only (no flip-flop IC)
 * Platform : Arduino Uno + SN7447 IC + 7-Segment Display
 * Toolchain: Arduino IDE / ArduinoDroid
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * State is maintained in software variables; 7447 decodes DCBA for display.
 * Contrast with FSM v1 (7447+7474) where hardware flip-flops hold state.
 */

#include <Arduino.h>

int W, X, Y, Z;
int D, C, B, A;
int currentState = 0;

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A); // LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D); // MSB
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Display current state
  digitalWrite(13, HIGH);
  delay(100);
  disp_7447(D, C, B, A);

  // Read input switches
  W = digitalRead(6);
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9);

  // Calculate next state
  switch (currentState) {
    case 0:
      A = 0;
      B = 0;
      C = 0;
      D = 0;
      break;
    case 1:
      A = 1;
      B = 0;
      C = 0;
      D = 0;
      break;
    case 2:
      A = 0;
      B = 1;
      C = 0;
      D = 0;
      break;
    case 3:
      A = 1;
      B = 1;
      C = 0;
      D = 0;
      break;
    case 4:
      A = 0;
      B = 0;
      C = 1;
      D = 0;
      break;
    case 5:
      A = 1;
      B = 0;
      C = 1;
      D = 0;
      break;
    case 6:
      A = 0;
      B = 1;
      C = 1;
      D = 0;
      break;
    case 7:
      A = 1;
      B = 1;
      C = 1;
      D = 0;
      break;
    case 8:
      A = 0;
      B = 0;
      C = 0;
      D = 1;
      break;
    case 9:
      A = 1;
      B = 0;
      C = 0;
      D = 1;
      break;
  }

  // Update current state with next state
  currentState = (currentState + 1) % 10;

  // Turn off display and delay
  digitalWrite(13, LOW);
  delay(500);
}