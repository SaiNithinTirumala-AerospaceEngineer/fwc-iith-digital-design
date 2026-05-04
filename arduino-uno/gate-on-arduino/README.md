# GATE On Arduino — Counter Circuit Analysis (GATE IN 2022)

**Platform:** Arduino Uno  
**GATE Question:** GATE IN 2022 — Determine the counter type of a given digital circuit  
**Toolchain:** Arduino IDE / ArduinoDroid

## The GATE Question

> The digital circuit shown implements which of the following?
> 1. A divide-by-5 counter
> 2. A divide-by-7 counter
> 3. A divide-by-8 counter
> 4. Does not function as a counter due to disjoint cycles of states

**Answer: Option 1 — Divide-by-5 counter**

## Circuit Logic

The circuit is a 3-bit shift-register feedback counter:

```
State registers: Q0, Q1, Q2
On each clock rising edge:
  q2 ← q1
  q1 ← q0
  q0 ← !q2   ← feedback: invert last stage, feed to first
On reset:  q0 = q1 = q2 = 0
```

## State Sequence

| Step | Q2 | Q1 | Q0 | Decimal |
|------|----|----|----|----|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 |
| 2 | 0 | 1 | 1 | 3 |
| 3 | 1 | 1 | 1 | 7 |
| 4 | 1 | 1 | 0 | 6 |
| 5 → 0 | 1 | 0 | 0 | 4 → repeats |

5 unique states before repeating → **divide-by-5**.

## Files

- `gate_counter_v1.ino` — Full implementation with CLK/RST input pins + Q0/Q1/Q2 outputs
- `gate_counter_v2.ino` — Simplified 3-state counter without external clock pin

## Arduino Pin Mapping (v1)

```
CLK → D2 (INPUT)    RST → D3 (INPUT)
Q0  → D4 (OUTPUT)   Q1  → D5 (OUTPUT)   Q2  → D6 (OUTPUT)
```

## Reference

GATE IN 2022 Question 46 — Digital Circuits section.  
See question image: [`../../questions/01_digital_design_ieee754.png`](../../questions/01_digital_design_ieee754.png)

![GATE On Arduino Workflow](../../outputs/nvim-termux-videos/7447_nvim.mp4)
