/*
 * FWC IITH – GATE On Arduino (Code 2): 3-state Sequence Counter
 * GATE Question (IN 2022): Same circuit — alternative implementation
 * Platform : Arduino Uno
 * Toolchain: Arduino IDE / ArduinoDroid
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * State sequence: X = !(Q2 OR Q3), Y = Q1, Z = Q2
 * Outputs on D2(Q1), D3(Q2), D4(Q3) with 3-second delay
 */

int Q1=0,Q2=0,Q3=0;
const int U_pin = 2;
const int V_pin = 3;
const int W_pin = 4;

void setup() {
  pinMode(U_pin, OUTPUT);
  pinMode(V_pin, OUTPUT);
  pinMode(W_pin, OUTPUT);
}

void loop(){
    
    int X=!(Q2||Q3);
    int Y=Q1;
    int Z=Q2;
    Q1=X;
    Q2=Y;
    Q3=Z;
    digitalWrite(2, Q1);
    digitalWrite(3, Q2);
    digitalWrite(4, Q3);
    delay(3000);
  

}