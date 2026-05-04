# K-Map — Boolean Minimisation + 7-Segment Display

**Platform:** Arduino Uno + SN7447 IC + 7-Segment Display  
**GATE Question:** Minimise a 4-variable Boolean function using Karnaugh Map  
**Toolchain:** Arduino IDE / ArduinoDroid

## Theory

A Karnaugh Map (K-Map) is a graphical method for minimising Boolean expressions.
Adjacent cells in the K-Map that differ by only one variable can be grouped to
eliminate that variable from the SOP expression.

### 4-Variable K-Map (W, X, Y, Z)

```
        YZ
WX  | 00 | 01 | 11 | 10 |
 00 |    |    |    |    |
 01 |    |    |    |    |
 11 |    |    |    |    |
 10 |    |    |    |    |
```

Groups of 1, 2, 4, or 8 adjacent cells → each group = one product term.

## Minimised SOP Expressions

```
A = 0
B = W'X'YZ' + W'XY'Z' + WX'YZ' + WXY'Z'
C = WXY'Z' + W'X'YZ' + WX'YZ' + W'XYZ'
D = WXYZ'  + W'X'Y'Z
```

These were derived by K-Map grouping and verified against the truth table.

## Truth Table (W=1, X=0, Y=0, Z=0 default)

| W | X | Y | Z | D | C | B | A | Display |
|---|---|---|---|---|---|---|---|---------|
| 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 2 |
| 0 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 4 |
| 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 2 |
| 0 | 0 | 0 | 1 | 1 | 0 | 0 | 0 | 8 |

## Output

![K-Map Output](../../outputs/output-videos/kmap_output.mp4)  
*[Video: K-Map minimised function output on 7-segment display]*
