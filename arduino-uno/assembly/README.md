# AVR Assembly — NOR/NAND Gate Logic

**Platform:** Arduino Uno (ATmega328P)  
**Problem:** Implement NOR gate (`nor_gate.asm`) and NAND gate (`nand_gate.asm`) in AVR assembly  
**Toolchain:** AVRA assembler → `.hex` → ArduinoDroid upload (precompiled)

## Build
```bash
# Inside Termux Debian:
avra nor_gate.asm    # generates nor_gate.hex
avra nand_gate.asm   # generates nand_gate.hex
# Flash via ArduinoDroid → Actions → Upload → Upload Precompiled
```

## Key Instructions Used
`SBI DDRB,5` — set PB5 (pin 13) as output  
`IN r16, PIND` — read port D pins  
`ANDI`, `LSR`, `EOR`, `AND`, `LSL` — bit manipulation  
`OUT PORTB, r16` — write to port B  
`RJMP start` — infinite loop
