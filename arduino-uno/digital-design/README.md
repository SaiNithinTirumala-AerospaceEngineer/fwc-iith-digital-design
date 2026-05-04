# Digital Design — IEEE-754 Floating Point on LCD

**Platform:** Arduino Uno + LCD JHD162A (16×2 display)  
**Problem:** Compute R3 = R1 / R2 where R1, R2 are IEEE-754 hex values; display on LCD  
**Toolchain:** Arduino IDE / ArduinoDroid (precompiled .hex via OTG)

## Circuit
```
LCD RS→D4, RW→D5, EN→D6, DB4→D7, DB5→D8, DB6→D9, DB7→D10
VEE→GND (contrast), LED+→5V via 220Ω, LED-→GND
```

## Key Code
```cpp
float R1_hex = 0x42200000;  // IEEE-754 hex
float R1 = *(float*)&R1_hex;  // type-pun to float
float R3 = R1 / R2;
lcd.print(R3, 8);
```

## Output
LCD displays R1, R2 for 3 seconds, then R3 = R1/R2.
