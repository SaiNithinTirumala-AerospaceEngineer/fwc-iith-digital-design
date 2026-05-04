# ARM Cortex-M4 — FreeRTOS + pygmy-sdk (VAMAN Board)

**Platform:** VAMAN board — QuickLogic EOS-S3 ARM Cortex-M4 core  
**GATE Question:** F(X,Y,Z,W) = Σm(0,1,3,11,14) — MUX-based combinational logic  
**Toolchain:** `arm-none-eabi-gcc` + `pygmy-sdk` + `TinyFPGA-Programmer`

## Theory

The GATE question involves a **4-to-1 multiplexer** with:

```
F(X, Y, Z, W) = XYZW' + XY'ZW + X'Y'Z'(W + W') + X'Y'W(Z + Z')
              = XYZW' + XY'ZW + X'Y'Z'W + X'Y'Z'W' + X'Y'WZ
              = Σm(0, 1, 3, 11, 14)
```

Minterms expanded in canonical form:

| Minterm | X | Y | Z | W | F |
|---------|---|---|---|---|---|
| 0       | 0 | 0 | 0 | 0 | 1 |
| 1       | 0 | 0 | 0 | 1 | 1 |
| 3       | 0 | 0 | 1 | 1 | 1 |
| 11      | 1 | 0 | 1 | 1 | 1 |
| 14      | 1 | 1 | 1 | 0 | 1 |

## Build Toolchain

```bash
# Inside Termux Debian — install ARM toolchain:
apt install gcc-arm-none-eabi libnewlib-arm-none-eabi

# Clone pygmy-sdk:
git clone --recursive https://github.com/optimuslogic/pygmy-dev

# Build:
cd arm-examples/blink/GCC_Project
make -j4
# Output: output/bin/blink.bin
```

## Flash to VAMAN

```bash
# Enter download mode:
# Press RIGHT button, immediately press LEFT button
# Green LED blinks → VAMAN in download mode

# Flash (from RPi or Ubuntu):
sudo python3 TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py \
  --port /dev/ttyACM0 \
  --m4app output/bin/blink.bin \
  --mode m4
```

## GPIO Pin Mapping (VAMAN)

| GPIO | Colour | Function |
|------|--------|----------|
| 18   | Blue   | X bit |
| 21   | Green  | Y bit |
| 22   | Red    | Z or W bit |

## Output

![ARM Output](../outputs/nvim-termux-videos/arm_output.mp4)  
*[Video: ARM Cortex-M4 truth-table LED demo — minterms cycling every 2 seconds]*
