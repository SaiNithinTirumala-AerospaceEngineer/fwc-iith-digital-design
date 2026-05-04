/*
 * FWC IITH – K-Map Variant 2 (Alternative Input State: W=1, X=1, Y=0, Z=0)
 * GATE Task: K-Map minimised function with different default input values
 * Platform : Arduino Uno + SN7447 IC + 7-Segment Display
 * Toolchain: Arduino IDE / ArduinoDroid
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Key difference from kmap.ino: A is NOT always 0 here —
 * A = (!W&&!Z) || (!W&&!X&&!Y)  — additional minterm coverage
 * Default inputs: W=1, X=1, Y=0, Z=0
 */

/Declaring all variables as integers
int Z=0,Y=0,X=1,W=1;
int D,C,B,A;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB

}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  A=(!W&&!Z)||(!W&&!X&&!Y);
  B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
  
disp_7447(D,C,B,A);  
}