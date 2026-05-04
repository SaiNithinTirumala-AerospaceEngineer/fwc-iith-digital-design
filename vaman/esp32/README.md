# ESP32 / VAMAN — Wireless Boolean Function (OTA Upload)

**Platform:** VAMAN board (ESP32 DEVKIT V1 module)  
**Problem:** Evaluate F(X,Y,Z) = X'Z' + YZ wirelessly via WiFi OTA  
**Toolchain:** PlatformIO + ArduinoOTA library

## Wiring (Upload via Arduino Uno as UART bridge)
```
Arduino TX → 1KΩ → 1KΩ(to GND) → VAMAN RX
Arduino RX → 1KΩ → 1KΩ(to GND) → VAMAN TX
Arduino RST → VAMAN RST
Arduino 3.3V → VAMAN 3.3V
Arduino GND → VAMAN GND
```

## Build & Flash
```bash
# Wired (first time):
pio run -t nobuild -t upload
# Wireless (OTA, subsequent):
pio run -t nobuild -t upload   # VAMAN connected to WiFi hotspot
```

## Truth Table
| X | Y | Z | F = X'Z' + YZ |
|---|---|---|---|
| 0 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 |
