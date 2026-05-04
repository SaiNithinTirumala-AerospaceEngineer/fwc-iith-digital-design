# Finite State Machine — 7447 + 7474 ICs

**Platform:** Arduino Uno + SN7447 IC + SN7474 IC + 7-Segment Display  
**GATE Question:** Implement a Mealy/Moore FSM; determine counter type  
**Toolchain:** Arduino IDE / ArduinoDroid

## Theory

A Finite State Machine (FSM) is a mathematical model with:
- **States (S):** distinct system configurations
- **Transitions (T):** conditions causing state changes
- **Inputs (I):** signals triggering transitions
- **Outputs (O):** signals produced per state or transition

**Moore Machine:** outputs depend only on current state.  
**Mealy Machine:** outputs depend on current state AND inputs.

This implementation uses **7474 D flip-flops** as state storage and
**7447 BCD decoder** to display the current state on a 7-segment display.

## State-Transition Equations

Derived from the GATE question's state-transition diagram:

```
Next state:
  A(t+1) = W'
  B(t+1) = W'X'Y + WX + W'Z
  C(t+1) = W'Z  + XY  + WY
  D(t+1) = W'X'Y'Z' + WZ

State update each clock cycle: W←A, X←B, Y←C, Z←D
```

## Hardware Architecture

```
Arduino D6–D9  →  Read current state (W, X, Y, Z)
Arduino D2–D5  →  Drive 7447 (D, C, B, A) → 7-Segment display
Arduino D13    →  Clock indicator LED
7474 IC        →  State storage (2 flip-flops per IC, 2 ICs = 4 bits)
7447 IC        →  BCD decode for display
```

## State Sequence (Sample)

| W | X | Y | Z | Next: A | B | C | D | Display |
|---|---|---|---|---------|---|---|---|---------|
| 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 | 9 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 3 (C, not displayed) |

## Output

![FSM Output](../../outputs/output-videos/fsm_output.mp4)  
*[Video: FSM states cycling on 7-segment display — hardware verification]*
