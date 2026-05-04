# FPGA — Verilog on VAMAN (QuickLogic EOS-S3)

**Platform:** VAMAN board (QuickLogic EOS-S3 FPGA fabric)  
**Problem:** Display `f = 1000 Hz` on LCD JHD162A using FPGA fabric  
**Toolchain:** ql_symbiflow (synthesis) + TinyFPGA-Programmer (flash)

## Files
- `helloworldfpga.v` — Verilog module (LCD state machine, 4-bit nibble mode)
- `quickfeather.pcf` — Pin constraint file (clock, LCD RS/E/DATA)

## Build & Flash
```bash
# Compile:
ql_symbiflow -compile -d ql-eos-s3 -P PU64 \
  -v helloworldfpga.v -t helloworldfpga \
  -p quickfeather.pcf -dump binary

# Flash (VAMAN in FPGA mode — green LED blinking):
sudo python3 tinyfpga-programmer-gui.py \
  --port /dev/ttyACM0 \
  --appfpga helloworldfpga.bin \
  --mode fpga
```

## Output
LCD displays: `f = 1000 Hz` (cycling every ~3 seconds with clear)
