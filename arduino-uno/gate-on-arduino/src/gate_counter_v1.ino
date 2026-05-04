/*
 * FWC IITH – GATE On Arduino (Code 1): 3-bit LFSR-style Counter
 * GATE Question (IN 2022): Determine if the digital circuit is a
 *   divide-by-5, divide-by-7, divide-by-8 counter, or non-functional
 * Platform : Arduino Uno — shift-register logic via software simulation
 * Toolchain: Arduino IDE / ArduinoDroid
 * Author   : Tirumala Sai Nithin | Employee ID: FWC22187
 * IIT Hyderabad – Future Wireless Communications
 *
 * Logic: q0 ← !q2 (feedback), q1 ← q0, q2 ← q1
 *        CLK on D2 (INPUT), RST on D3 (INPUT)
 *        Outputs Q0→D4, Q1→D5, Q2→D6
 *
 * Answer: This implements a divide-by-5 counter (GATE IN 2022)
 */

// Define the pins for the clock, reset and output signals
#define CLK 2
#define RST 3
#define Q0 4
#define Q1 5
#define Q2 6

// Define the variables for the current and previous states of the clock and reset signals
int clkState = 0;
int prevClkState = 0;
int rstState = 0;
int prevRstState = 0;

// Define the variables for the output signals
int q0 = 0;
int q1 = 0;
int q2 = 0;

void setup() {
  // Set the clock and reset pins as inputs
  pinMode(CLK, INPUT);
  pinMode(RST, INPUT);
  
  // Set the output pins as outputs
  pinMode(Q0, OUTPUT);
  pinMode(Q1, OUTPUT);
  pinMode(Q2, OUTPUT);
}

void loop() {
  // Read the current states of the clock and reset signals
  clkState = digitalRead(CLK);
  rstState = digitalRead(RST);
  
  // Check if the reset signal is high
  if (rstState == HIGH && prevRstState == LOW) {
    // Reset the output signals to zero
    q0 = 0;
    q1 = 0;
    q2 = 0;
  }
  
  // Check if the clock signal has a rising edge
  if (clkState == HIGH && prevClkState == LOW) {
    // Shift the output signals to the next stage
    q2 = q1;
    q1 = q0;
    q0 = !q2; // Invert the output of the last stage and feed it back to the first stage
  }
  
  // Write the output signals to the corresponding pins
  digitalWrite(Q0, q0);
  digitalWrite(Q1, q1);
  digitalWrite(Q2, q2);
  
  // Update the previous states of the clock and reset signals
  prevClkState = clkState;
  prevRstState = rstState;
}