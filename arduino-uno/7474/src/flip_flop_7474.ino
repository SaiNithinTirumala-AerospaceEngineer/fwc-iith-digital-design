/*
 * FWC IITH – 7474 IC (Dual D Flip-Flop Experiment)
 * GATE Question: Sequential state transitions using 7474 D flip-flop IC
 * Platform: Arduino Uno + SN7474 IC + SN7447 IC + 7-Segment Display
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Pin mapping:
 *   Outputs → D2(A/LSB), D3(B), D4(C), D5(D/MSB)
 *   Inputs  → D6(W), D7(X), D8(Y), D9(Z)
 */

#include <Arduino.h>

int W, X, Y, Z;
int D, C, B, A;

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A);
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);
}

void setup() {
  pinMode(2, OUTPUT); pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); pinMode(5, OUTPUT);
  pinMode(6, INPUT);  pinMode(7, INPUT);
  pinMode(8, INPUT);  pinMode(9, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  disp_7447(D, C, B, A);

  W = digitalRead(6);
  X = digitalRead(7);
  Y = digitalRead(8);
  Z = digitalRead(9);

  // Next-state logic
  A = !W;
  B = (!W && !X && Y) || (W && X) || (!W && Z);
  C = (!W && Z) || (X && Y) || (W && Y);
  D = (!W && !X && !Y && !Z) || (W && Z);

  W = A; X = B; Y = C; Z = D;

  digitalWrite(13, LOW);
  delay(500);
}
