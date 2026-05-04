# 7474 IC — Dual D Flip-Flop Sequential Logic

**Platform:** Arduino Uno + SN7474 IC + SN7447 IC + 7-Segment Display  
**GATE Question:** Implement sequential state transitions using D flip-flop IC  
**Toolchain:** Arduino IDE / ArduinoDroid

## Theory

The SN7474 contains two independent positive-edge-triggered D flip-flops with
active-LOW set (S̄) and reset (R̄) inputs. Each flip-flop stores one bit.

```
On rising CLK edge:  Q(t+1) = D
Q̄ = complement of Q
```

In this experiment, Arduino simulates the clock and reads/writes state through
digital pins, while the 7447 decodes the current state for 7-segment display.

## Pin Configuration (7474 IC)

| Pin | Signal | Description |
|-----|--------|-------------|
| 1   | CLR̄₁  | Active-LOW async clear FF1 |
| 2   | D₁    | Data input FF1 |
| 3   | CLK₁  | Clock FF1 |
| 4   | PR̄₁  | Active-LOW async preset FF1 |
| 5   | Q₁    | Output FF1 |
| 6   | Q̄₁   | Complement output FF1 |
| 7   | GND   | Ground |
| 8   | Q̄₂   | Complement output FF2 |
| 9   | Q₂    | Output FF2 |
| 10  | PR̄₂  | Active-LOW async preset FF2 |
| 11  | CLK₂  | Clock FF2 |
| 12  | D₂    | Data input FF2 |
| 13  | CLR̄₂  | Active-LOW async clear FF2 |
| 14  | VCC   | Power supply |

## Arduino Pin Mapping

```
D2 → 7447 A (LSB output)    D6 → Input switch W
D3 → 7447 B                 D7 → Input switch X
D4 → 7447 C                 D8 → Input switch Y
D5 → 7447 D (MSB output)    D9 → Input switch Z
D13 → Clock indicator LED
```

## Next-State Logic

```cpp
A = !W;
B = (!W && !X && Y) || (W && X) || (!W && Z);
C = (!W && Z) || (X && Y) || (W && Y);
D = (!W && !X && !Y && !Z) || (W && Z);
```

These equations were derived from the GATE question's state-transition diagram.

## Output

![7474 Output](../../outputs/output-videos/7474_output.mp4)  
*[Video: 7474 flip-flop experiment — sequential state changes on 7-segment]*

## Truth Table (from Internship Report, Ch. 5.2.4)

| W | X | Y | Z | → | D | C | B | A | Display |
|---|---|---|---|---|---|---|---|---|---------|
| 0 | 0 | 0 | 0 | → | 1 | 0 | 0 | 1 | 9 |
| 1 | 0 | 0 | 0 | → | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | → | 0 | 1 | 1 | 1 | 7 |
| 1 | 1 | 0 | 0 | → | 0 | 1 | 1 | 0 | 6 |
| 0 | 0 | 1 | 0 | → | 1 | 1 | 0 | 1 | 13 |
| 1 | 0 | 1 | 0 | → | 0 | 1 | 0 | 0 | 4 |
| 0 | 1 | 1 | 0 | → | 0 | 1 | 1 | 1 | 7 |
| 1 | 1 | 1 | 0 | → | 0 | 1 | 1 | 0 | 6 |
| 0 | 0 | 0 | 1 | → | 1 | 0 | 0 | 1 | 9 |
| 1 | 0 | 0 | 1 | → | 1 | 1 | 0 | 0 | 12 |
| 0 | 1 | 0 | 1 | → | 1 | 1 | 1 | 1 | 15 |
| 1 | 1 | 0 | 1 | → | 0 | 1 | 1 | 0 | 6 |

For 0 the LED does not glow; for 1 the LED glows.
