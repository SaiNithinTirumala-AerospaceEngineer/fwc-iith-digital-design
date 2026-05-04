/*
 * FWC IITH – Digital Design (IEEE-754 Floating Point)
 * GATE Question: IEEE-754 floating-point arithmetic R3 = R1 / R2
 * Platform: Arduino Uno + LCD JHD162A (16×2)
 * Author: Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 */

#include <LiquidCrystal.h>

// LCD pin connections: RS, RW, EN, D4, D5, D6, D7
LiquidCrystal lcd(4, 5, 6, 7, 8, 9, 10);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();

  // IEEE-754 hex representations
  float R1_hex = 0x42200000;  // 40.0 in IEEE-754
  float R2_hex = 0xC1200000;  // -10.0 in IEEE-754

  // Type-pun hex to float
  float R1 = *(float*)&R1_hex;
  float R2 = *(float*)&R2_hex;

  // Compute R3 = R1 / R2
  float R3 = R1 / R2;

  // Display R1, R2
  lcd.print("R1 = ");
  lcd.print(R1, 8);
  lcd.setCursor(0, 1);
  lcd.print("R2 = ");
  lcd.print(R2, 8);
  delay(3000);
  lcd.clear();

  // Display R3
  lcd.print("R3 = R1/R2 =");
  lcd.setCursor(0, 1);
  lcd.print(R3, 8);
}

void loop() {
  // Static display — nothing to loop
}
