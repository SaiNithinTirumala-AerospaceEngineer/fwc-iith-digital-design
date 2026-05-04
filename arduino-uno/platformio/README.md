# PlatformIO — Arduino Framework via PlatformIO CLI

**Platform:** Arduino Uno  
**GATE Question:** Boolean function F(A,B,C) evaluated and displayed on LED  
**Toolchain:** PlatformIO CLI (`pio run`) inside Termux Debian — NOT Arduino IDE

## Why PlatformIO vs Arduino IDE?

PlatformIO is a professional embedded development ecosystem that supports
100+ platforms and frameworks from a single CLI. Key advantages:

- Dependency management via `platformio.ini`
- Works headlessly (no GUI) — perfect for Termux/Android
- Produces `.hex` / `.bin` compatible with ArduinoDroid upload
- Supports AVR, ESP32, STM32, ARM from one toolchain

## Project Structure

```
platformio/
├── platformio.ini     # Board config: platform, board, framework
└── src/
    └── main.cpp       # Must include <Arduino.h> (not .ino)
```

## Build & Flash

```bash
# Inside Termux Debian — navigate to platformio/ folder:
pio run                          # compile only
pio run -t nobuild -t upload     # upload via USB (if connected)

# OR compile then flash via ArduinoDroid:
# File: .pio/build/uno/firmware.hex
# ArduinoDroid → Actions → Upload → Upload Precompiled → firmware.hex
```

## platformio.ini

```ini
[env:uno]
platform  = atmelavr
board     = uno
framework = arduino
```

## Boolean Function

```
F(A, B, C) = BC + A'
```

Truth table:

| A | B | C | F |
|---|---|---|---|
| 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 |

## Output

![PlatformIO Output](../../outputs/output-videos/platformio_output.mp4)  
*[Video: PlatformIO compiled code — LED reflects Boolean function output]*
