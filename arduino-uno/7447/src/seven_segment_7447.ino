/*
 * FWC IITH – 7447 IC (BCD to 7-Segment Decoder)
 * GATE Question: Display digit 5 using 7447 BCD decoder IC
 * Platform: Arduino Uno + SN7447 IC + Common-Anode 7-Segment Display
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Pin mapping: D2→A(LSB), D3→B, D4→C, D5→D(MSB)
 * 7447 drives 7-segment directly (active-LOW outputs)
 */

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A);  // LSB
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);  // MSB
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // BCD 0101 = decimal 5
  disp_7447(0, 1, 0, 1);
}
