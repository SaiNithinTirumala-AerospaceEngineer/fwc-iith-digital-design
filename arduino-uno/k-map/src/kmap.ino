/*
 * FWC IITH – Karnaugh Map (Boolean Minimisation)
 * GATE Question: Minimise F(W,X,Y,Z) using K-Map; display result via 7447
 * Platform: Arduino Uno + SN7447 IC + 7-Segment Display
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Minimised SOP expressions (obtained from K-Map):
 *   A = 0
 *   B = W'X'YZ' + W'XY'Z' + WX'YZ' + WXY'Z'   (wait — simplified below)
 *     = (W⊕X) · Y' · Z'  |  see K-Map notes
 *   C = WX·Y'Z' + W'X'YZ' + WX'YZ' + W'XYZ'
 *   D = WXYZ' + W'X'Y'Z
 */

int Z = 0, Y = 0, X = 0, W = 1;  // Default input state
int D, C, B, A;

void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A);
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  A = 0;
  B = (W && !X && !Y && !Z) || (!W && X && !Y && !Z) ||
      (W && !X && Y && !Z)  || (!W && X && Y && !Z);
  C = (W && X && !Y && !Z) || (!W && !X && Y && !Z) ||
      (W && !X && Y && !Z)  || (!W && X && Y && !Z);
  D = (W && X && Y && !Z)  || (!W && !X && !Y && Z);

  disp_7447(D, C, B, A);
}
