# Methodology — FWC IITH Digital Design

**Author:** Tirumala Sai Nithin | FWC22187 | IIT Hyderabad  
**Internship:** Advanced 5G/6G Wireless Communications · Module 1 · Dec 2023 – Mar 2024  
**Supervisor:** Prof. G. V. V. Sharma, Associate Professor, Dept. of EE

---

## Chapter 1 — Tools & Environment

### 1.1 Termux Setup (Android Terminal)

```bash
# Step 1 — Install from F-Droid (not Google Play):
#   F-Droid → install Termux, Termux:API

# Step 2 — Give storage access
termux-setup-storage

# Step 3 — Upgrade packages
pkg upg
# OR:
apt update && apt upgrade

# Step 4 — Install mandatory packages
apt install build-essential openssh curl git wget subversion \
  silversearcher-ag imagemagick proot proot-distro python \
  bsdtar mutt nmap neovim

# Step 5 — Install Debian inside Termux
proot-distro install debian
proot-distro login debian

# Inside Debian proot:
apt update && apt upgrade
apt install apt-utils build-essential cmake neovim git wget \
  subversion imagemagick nano ranger python3-venv

# Python3
apt install python3-pip python3-numpy python3-scipy \
  python3-matplotlib python3-mpmath python3-sympy python3-cvxopt

# Neovim + Ranger
apt install neovim ranger libxtst-dev libx11-dev python3-pynvim
pip3 install ueberzug

# LaTeX
apt install texlive-full gnumeric

# AVR toolchain
apt install avra avrdude gcc-avr avr-libc
```

### 1.2 Neovim Setup (vim-plug)

```bash
# Install vim-plug
curl -fLo ~/.local/share/nvim/site/autoload/plug.vim --create-dirs \
  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

# Download init.vim config
curl -fLo ~/.config/nvim/init.vim --create-dirs \
  https://raw.githubusercontent.com/gadepall/termux/main/neovim/init.vim

# Install plugins
nvim ~/.config/nvim/init.vim
# Inside nvim:
# :PlugInstall
# :qa!

# Update remote plugins
nvim
# :UpdateRemotePlugins
# :q!
```

### 1.3 Arduino IDE & ArduinoDroid

**Arduino IDE** — desktop application for Windows/Mac/Linux.

**ArduinoDroid** — Android app for programming Arduino from phone:
1. Install ArduinoDroid from APKPure
2. Open → grant all permissions
3. Connect Arduino to phone via USB OTG cable
4. To flash precompiled `.hex` / `.bin`:
   - Actions → Upload → Upload Precompiled
   - Navigate to `.pio/build/uno/firmware.hex`
   - Select the file → upload

### 1.4 LaTeX (pdflatex on Android)

```bash
proot-distro login debian
cd /sdcard/latex-project/
nvim filename.tex       # write LaTeX
pdflatex filename.tex   # compile
termux-open filename.pdf # view PDF
```

### 1.5 Neovim Key Commands

| Command | Mode | Action |
|---------|------|--------|
| `nvim` | Terminal | Open editor |
| `ALT+O` | Normal | Open file picker |
| `i` | Normal | Enter insert mode |
| `o` | Normal | Insert mode, next line |
| `Esc` | Insert | Return to normal |
| `:w` | Normal | Save |
| `:wq` | Normal | Save and close |
| `:q!` | Normal | Close without saving |
| `ranger` | Terminal | File manager |
| `Shift+S` | Ranger | Shell at location |
| `dd` | Normal | Delete line |
| `yy` | Normal | Copy line |
| `p` | Normal | Paste |
| `:%s@find@replace@gc` | Normal | Find and replace all |

See `nvim_shortcut_keys.pdf` for the complete 2-page reference.

### 1.6 Ubuntu Dual Boot Setup

1. **Backup data** before starting
2. **Download** Ubuntu ISO from ubuntu.com/download
3. **Create bootable USB** using Rufus (Windows) or balenaEtcher (Mac/Linux)
4. **Shrink Windows partition**: Win+X → Disk Management → Shrink Volume (≥20 GB)
5. **Disable Fast Startup**: Control Panel → Power Options → Choose what power buttons do → uncheck Fast Startup
6. **Disable Secure Boot**: BIOS → Security tab → Secure Boot → Disabled
7. **Boot from USB**: BIOS → Boot order → USB first
8. **Install**: Select "Install Ubuntu alongside Windows Boot Manager"
9. **GRUB bootloader** appears at restart — choose Ubuntu or Windows

---

## Chapter 2 — Platform Methodologies

### 2.1 Seven Segment (Direct Drive)

1. Open Termux → `proot-distro login debian`
2. Edit code: `nvim seven_segment_direct.ino`
3. Compile in ArduinoDroid
4. Connect Arduino via OTG → upload `.hex`
5. Pin map: a→D7, b→D8, c→D2, d→D3, e→D4, f→D6, g→D5

### 2.2 7447 BCD Decoder

1. Wire: D2→A(LSB), D3→B, D4→C, D5→D(MSB) on 7447 IC
2. LT/RBI/BI pins → 5V (enable decode)
3. Code: `disp_7447(D, C, B, A)` → sets BCD value

### 2.3 K-Map Boolean Minimisation

1. Draw 4-variable K-Map (W, X, Y, Z) in Gray code order
2. Group adjacent 1s in powers of 2 (1, 2, 4, 8 cells)
3. Write minimised SOP: A=0, B=…, C=…, D=…
4. Implement in `loop()` using `&&`, `||`, `!`
5. Drive 7447 via `disp_7447(D, C, B, A)`

### 2.4 7474 D Flip-Flop

1. Read state (W, X, Y, Z) from digital pins D6–D9
2. Compute next state using Boolean equations each 500ms
3. Drive 7447 on D2–D5 to display current state
4. D13 LED pulses as visual clock indicator

### 2.5 Digital Design (C++ / PlatformIO)

1. Open Termux → `proot-distro login debian`
2. Navigate to code using RANGER: `ranger` → navigate → `Shift+S`
3. Execute: `pio run` (compiles code)
4. Open ArduinoDroid on mobile
5. Connect Arduino via OTG cable
6. Actions → Upload → Upload Precompiled → navigate to `.pio/build/uno/firmware.hex`

### 2.6 Assembly Task (AVRA)

1. Open Termux → `proot-distro login debian`
2. Navigate to assembly folder using RANGER
3. Edit: `nvim filename.asm`
4. Assemble: `avra filename.asm` → generates `.hex`
5. Flash via ArduinoDroid precompiled upload

### 2.7 AVR-GCC Task

1. Open Termux → `proot-distro login debian`
2. Navigate to avr-gcc folder using RANGER → `Shift+S`
3. Edit: `nvim main.c`
4. Compile: `make` → generates `main.hex`
5. Flash via ArduinoDroid precompiled upload

### 2.8 ESP32 Task (VAMAN board)

1. Open Termux → `proot-distro login debian`
2. Navigate to ESP32 code location
3. Edit code: `nvim main.cpp`
4. Compile: `pio run`
5. Make wired connections (Arduino Uno as UART bridge):
   - Arduino RST → VAMAN RST
   - Arduino TX → 1KΩ → 1KΩ(to GND) → VAMAN RX
   - Arduino RX → 1KΩ → 1KΩ(to GND) → VAMAN TX
   - Arduino 3.3V → VAMAN 3.3V, GND → GND
6. Flash firmware (hold EN pin during upload start, release after)
7. Remove wired connections after successful flash
8. Connect VAMAN to phone hotspot
9. Verify in hotspot connected devices list
10. Upload wirelessly: `pio run -t nobuild -t upload`

### 2.9 ARM Task (VAMAN board M4 core)

1. Open Ubuntu (or Termux Debian)
2. Navigate to ARM code using RANGER → `Shift+S`
3. Edit: `nvim src/main.c`
4. Compile: `make -j4` → generates `output/bin/blink.bin`
5. Transfer to RPi: `scp output/bin/blink.bin pi@192.168.x.x:`
6. On RPi: enter VAMAN download mode:
   - Connect VAMAN via USB
   - Press RIGHT button → immediately press LEFT button
   - Green LED blinks = download mode
7. Flash: `sudo python3 TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0 --m4app blink.bin --mode m4`

### 2.10 FPGA Task (VAMAN QuickLogic EOS-S3)

1. Open Ubuntu terminal
2. Navigate to FPGA code: `cd /path/to/fpga/`
3. Edit Verilog: `nvim helloworldfpga.v`
4. Edit pin constraints: `nvim quickfeather.pcf`
5. Compile:
   ```bash
   ql_symbiflow -compile \
     -src /path/to/fpga/blink \
     -d ql-eos-s3 -P PU64 \
     -v helloworldfpga.v \
     -t helloworldfpga \
     -p quickfeather.pcf \
     -dump binary
   ```
6. Put VAMAN in upload mode (green LED on)
7. Copy `.bin` to home directory
8. Flash:
   ```bash
   sudo python3 /path/to/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py \
     --port /dev/ttyACM0 \
     --appfpga helloworldfpga.bin \
     --mode fpga
   ```

---

## Chapter 3 — Installation Commands

### 3.1 PlatformIO

```bash
# Inside proot-distro Debian:
pip3 install platformio

# Download sample project
svn co https://github.com/gadepall/fwc-1/trunk/ide/piosetup/codes
cd codes
pio run

# Connect Arduino → upload
pio run -t nobuild -t upload
```

### 3.2 ESP32 (on Termux)

```bash
apt update && apt upgrade
apt install python3-pip
pip3 install platformio

# Download sample for ESP32
svn co https://github.com/gadepall/termux/trunk/pio/Projects/hi
pio lib --global install "stempedia/DabbleESP32"

# Install xtensa + espressif32
cd Projects/hi
pio run
# Output: .pio/build/esp32doit-devkit-v1/firmware.bin
```

### 3.3 ARM Toolchain

```bash
proot-distro login debian
apt update && apt upgrade
apt install openssh-server
apt install build-essential libssl-dev libffi-dev python3-dev \
  bison flex git tcl-dev tcl-tclreadline libreadline-dev \
  autoconf libtool make automake texinfo pkg-config \
  libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi \
  libnewlib-arm-none-eabi telnet python3 apt-utils \
  libxslt-dev python3-lxml python3-simplejson cmake curl python3-pip

# Test toolchain
arm-none-eabi-gcc --version

# Clone pygmy-sdk
git clone --recursive https://github.com/optimuslogic/pygmy-dev

# Install TinyFPGA-Programmer (on RPi)
git clone --recursive https://github.com/QuickLogic-Corp/TinyFPGA-Programmer-Application.git
sudo apt install python3-pip
sudo pip3 install tinyfpgab pyserial
sudo reboot
```

### 3.4 FPGA (ql_symbiflow on Ubuntu)

```bash
# Install dependencies
sudo apt install openssh-server sshpass build-essential libssl-dev \
  libffi-dev python3-dev bison flex git tcl-dev tcl tcl-tclreadline \
  libreadline-dev autoconf libtool make automake texinfo pkg-config \
  libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi \
  libnewlib-arm-none-eabi telnet python3 apt-utils \
  libxslt-dev cmake curl python3-pip python3-venv -y
pip3 install gdown lxml simplejson

# Set up symbiflow
export INSTALL_DIR=/home/USERNAME/Desktop/fpga/symbiflow
tar -C $INSTALL_DIR -xvf arch.tar.gz
export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"

# Add to .bashrc permanently:
export INSTALL_DIR=/home/nithin/Desktop/fpga/symbiflow
export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"
export PATH=/home/nithin/Desktop/fpga/symbiflow/bin:$PATH

# Verify tools
vpr -h
yosys -h
qlfasm -h
ql_symbiflow -h
```

---

## Circuit Connections

### LCD JHD162A → Arduino Uno

| LCD Pin | Signal | Arduino |
|---------|--------|---------|
| 1 | VSS | GND |
| 2 | VCC | 5V |
| 3 | VEE | GND (no potentiometer) |
| 4 | RS | D4 |
| 5 | RW | D5 |
| 6 | EN | D6 |
| 11 | DB4 | D7 |
| 12 | DB5 | D8 |
| 13 | DB6 | D9 |
| 14 | DB7 | D10 |
| 15 | LED+ | 5V via 220Ω |
| 16 | LED- | GND |

### SN7447 → Arduino Uno

| 7447 Pin | Signal | Arduino |
|----------|--------|---------|
| 7 | A (LSB) | D2 |
| 1 | B | D3 |
| 2 | C | D4 |
| 6 | D (MSB) | D5 |
| 3 | LT | 5V |
| 4 | RBI | 5V |
| 5 | BI/RBO | 5V |
| 16 | VCC | 5V |
| 8 | GND | GND |

### VAMAN ESP32 Upload (Arduino as UART bridge)

```
Arduino RST  ────────────────────────── VAMAN RST
Arduino TX   ──[1KΩ]──[1KΩ to GND]─── VAMAN RX
Arduino RX   ──[1KΩ]──[1KΩ to GND]─── VAMAN TX
Arduino 3.3V ────────────────────────── VAMAN 3.3V
Arduino GND  ────────────────────────── VAMAN GND
                   GPIO0 (EN) ─────── hold LOW during upload start
                   GPIO0 (0)  ─────── release after upload begins
```

---

## Pin Lists Reference

See [`pin_lists.txt`](pin_lists.txt) for:
- LCD JHD162A complete 16-pin list (VSS to LED-)
- VAMAN ESP32 DEVKIT V1 complete GPIO list (right side + left side)

---

## Neovim Workflow (NVIM Screen Recording Sequence)

**For LaTeX:**
```
proot-distro login debian → clear → nvim
ALT+O → navigate to .tex file → ENTER
CTRL+ALT+C → proot-distro login debian
cd /sdcard → pdflatex filename.tex → termux-open filename.pdf
```

**For AVR-GCC:**
```
proot-distro login debian → clear → nvim
ALT+O → navigate to file → ENTER
CTRL+ALT+C → proot-distro login debian → ranger
Navigate to src folder → SHIFT+S → make
```

**For Assembly:**
```
proot-distro login debian → clear → nvim
ALT+O → navigate to .asm file → ENTER
CTRL+ALT+C → proot-distro login debian
cd /sdcard/assembly → avra filename.asm
```
