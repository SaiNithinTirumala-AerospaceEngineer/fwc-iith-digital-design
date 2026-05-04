/*
 * FWC IITH – Seven Segment Display (Direct Segment Drive, No Decoder IC)
 * GATE Task: Display digits 0-9 directly on 7-segment display by
 *            controlling each segment pin individually from Arduino
 * Platform : Arduino Uno + Common-Cathode 7-Segment Display + Buzzer + Button
 * Toolchain: Arduino IDE / ArduinoDroid
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Pin mapping (segment → Arduino pin):
 *   a → D7,  b → D8,  c → D2,  d → D3
 *   e → D4,  f → D6,  g → D5
 *   Button → A0,  Buzzer → D10
 *
 * Note: This platform directly drives each of the 7 segments individually.
 * Contrast with 7447 platform which uses a decoder IC instead.
 * On button press, simulates a dice roll (random digit 1-6) with beep feedback.
 */

include <Arduino.h>

#define aPin 7   //        
#define bPin 8   //      ___
#define cPin 2   //     |  A  |
#define dPin 3   //   F |___| B
#define ePin 4   //     |  G  |
#define fPin 6   //   E |___| C
#define gPin 5   //        D     O dot

// Pin configuration
#define PIN_BUTTON A0
#define PIN_BUZZER 10

const byte PIN_CHAOS = A5; // Unconnected analog pin used to initialize RNG

// Other configuration
const unsigned int BEEP_FREQUENCY = 3000;

int On = 1; // <On=0; for Common anode><On=1; for Common cathode>
int Off;

// Function prototypes
void showNumber(int x);
void rollTheDice(int count, int delayLength);
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void zero(); // Define zero function

void setup() {
  randomSeed(analogRead(PIN_CHAOS));

  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);

  pinMode(PIN_BUTTON, INPUT_PULLUP);    // On button pin as input with pullup
  pinMode(PIN_BUZZER, OUTPUT);      // On buzzer pin as output

  // Indicate that the system is ready
  for (int i = 0; i <= 9; i++) {
    showNumber(i);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 100);
    delay(300);
  }
  tone(PIN_BUZZER, BEEP_FREQUENCY, 250);  // Beep when done
  delay(1000);              // Wait for 1 second
}

void loop() {
  // Wait for the button to be pressed, then run the test routine
  int buttonState = digitalRead(PIN_BUTTON);
  if (buttonState == LOW) {
    rollTheDice(10, 100);          // Show the rolling animation with a delay of 100 milliseconds
    rollTheDice(5, 200);
    rollTheDice(3, 300);
    rollTheDice(1, 100);
    tone(PIN_BUZZER, BEEP_FREQUENCY, 250);  // Beep when done
  }
}

void rollTheDice(int count, int delayLength) {
  for (int i = 0; i < count; i++) {
    int number = random(1, 7);      // Get a random number from 1 to 6
    tone(PIN_BUZZER, BEEP_FREQUENCY, 5);  // Beep very shortly ("click")
    showNumber(number);           // Show the number
    delay(delayLength);           // Wait
  }
}

void showNumber(int x) {
  if (On == 1) {
    Off = 0;
  } else {
    Off = 1;
  }

  switch (x) {
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: zero(); break;
  }
}

void one() {
  digitalWrite(aPin, On); //
  digitalWrite(bPin, Off);  //      |
  digitalWrite(cPin, Off);  //      |
  digitalWrite(dPin, On); //
  digitalWrite(ePin, On); //
  digitalWrite(fPin, On);
  digitalWrite(gPin, On);
  delay(500);
}

void two() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, Off);  //      | 
  digitalWrite(cPin, On); //  __|
  digitalWrite(dPin, Off);  // |     
  digitalWrite(ePin, Off);  // |__
  digitalWrite(fPin, On);
  digitalWrite(gPin, Off);
  delay(500);
}

void three() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, Off);  //      |
  digitalWrite(cPin, Off);  //  __|
  digitalWrite(dPin, Off);  //      |
  digitalWrite(ePin, On); //  __|
  digitalWrite(fPin, On);
  digitalWrite(gPin, Off);
  delay(500);
}

void four() {
  digitalWrite(aPin, On); //
  digitalWrite(bPin, Off);  // |    |
  digitalWrite(cPin, Off);  // |__|
  digitalWrite(dPin, On); //
  digitalWrite(ePin, On); //
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
  delay(500);
}

void five() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, On); // |
  digitalWrite(cPin, Off);  // |__
  digitalWrite(dPin, Off);  //      |
  digitalWrite(ePin, On); //  __|
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
  delay(500);
}

void six() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, On); // |
  digitalWrite(cPin, Off);  // |__
  digitalWrite(dPin, Off);  // |    |
  digitalWrite(ePin, Off);  // |__|
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
  delay(500);
}

void seven() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, Off);  //      |
  digitalWrite(cPin, Off);  //      |
  digitalWrite(dPin, On); //
  digitalWrite(ePin, On); //
  digitalWrite(fPin, On);
  digitalWrite(gPin, On);
  delay(500);
}

void eight() {
  digitalWrite(aPin, Off); //  __
  digitalWrite(bPin, Off); // |    |
  digitalWrite(cPin, Off); // |__|
  digitalWrite(dPin, Off); // |    |
  digitalWrite(ePin, Off); // |__|
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
  delay(500);
}

void nine() {
  digitalWrite(aPin, Off);  //  __
  digitalWrite(bPin, Off);  // |    |
  digitalWrite(cPin, Off);  // |__|
  digitalWrite(dPin, Off);  //      |
  digitalWrite(ePin, On); //  __
  digitalWrite(fPin, Off);
  digitalWrite(gPin, Off);
  delay(500);
}

void zero() {
  digitalWrite(aPin, Off); //  __
  digitalWrite(bPin, Off); // |    |
  digitalWrite(cPin, Off); // |    |
  digitalWrite(dPin, Off); // |   
  digitalWrite(ePin, Off); // |__|
  digitalWrite(fPin, Off); 
  digitalWrite(gPin, On);
}