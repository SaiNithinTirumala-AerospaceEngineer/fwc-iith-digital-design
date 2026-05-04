.include "/sdcard/assembly/m328Pdef.inc"

; Set pin 13 (PB5) as output
    SBI DDRB,5

; Clear all bits in port D
    ldi r16, 0b00000000
    out DDRD, r16

start:
; Read input from port D
    in r16, PIND
    mov r17, r16

; Extract the relevant bits for NOR gate
    andi r16, 0b00000100
    LSR r16
    LSR r16
    ldi r18, 0b00000001
    eor r16, r18

; Move the result to r19
    mov r19, r17
    ldi r19, 0b00001000
    LSR r19
    LSR r19
    LSR r19

; Perform AND operation
    and r16, r19

; Shift left five times
    LSL r16
    LSL r16
    LSL r16
    LSL r16
    LSL r16

; Output the result to pin 13 (PB5)
    out PORTB, r16

; Infinite loop
    rjmp start
