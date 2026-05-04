# 7447 IC — BCD to 7-Segment Decoder Experiment

**Platform:** Arduino Uno + SN7447AN IC + Common-Anode 7-Segment Display  
**GATE Question:** Drive a 7-segment display to show a specific decimal digit  
**Toolchain:** Arduino IDE / ArduinoDroid (precompiled `.hex` via OTG cable)

## Theory

The SN7447 is a TTL BCD-to-seven-segment decoder/driver IC. It accepts a 4-bit
Binary Coded Decimal (BCD) input (pins A–D) and drives the seven segments (a–g)
of a common-anode display with **active-LOW** outputs. No external current-limiting
resistors are needed on the segment outputs — the IC drives them directly.

| BCD (DCBA) | Decimal | Segments lit |
|-----------|---------|-------------|
| 0000 | 0 | a b c d e f |
| 0001 | 1 | b c |
| 0101 | 5 | a f g c d |
| 1001 | 9 | a b c d f g |

## Circuit Connections

```
Arduino  →  7447 IC
  D2     →  A  (pin 7)  LSB
  D3     →  B  (pin 1)
  D4     →  C  (pin 2)
  D5     →  D  (pin 6)  MSB
  5V     →  VCC (pin 16), LT (pin 3), RBI (pin 4), BI/RBO (pin 5)
  GND    →  GND (pin 8)

7447 IC  →  Common-Anode 7-Segment Display
  a–g outputs (pins 9–15) → segment pins a–g
  Common Anode → 5V
```

## Code Explanation

```cpp
void disp_7447(int D, int C, int B, int A) {
  digitalWrite(2, A);  // LSB → 7447 pin A
  digitalWrite(3, B);
  digitalWrite(4, C);
  digitalWrite(5, D);  // MSB → 7447 pin D
}

void loop() {
  disp_7447(0, 1, 0, 1);  // BCD 0101 = decimal 5
}
```

## Output

The display shows digit **5**. The `disp_7447()` helper function is reused
across K-Map, 7474, and FSM platforms.

![7447 Output](../../outputs/output-videos/7447_output.mp4)  
*[Video: 7447 hardware output — digit displayed on 7-segment]*
