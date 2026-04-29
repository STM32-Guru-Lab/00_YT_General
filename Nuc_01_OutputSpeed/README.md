# Nuc_01_OutputSpeed

GPIO Output Speed Test mit NUCLEO-F103RB (STM32F103RB, Cortex-M3).

## Voraussetzungen (1× pro Rechner)

```bash
sudo apt install cmake make openocd
```

## Aufbauen & Flashen

### Release (optimiert: `-O2`)

```bash
cmake --preset Release
cmake --build build/Release --target flash
```

### Debug (keine Optimierung: `-O0`)

```bash
cmake --preset Debug
cmake --build build/Debug --target flash
```

### Einzeiler (Script)

```bash
./flash.sh              # Release bauen + flashen
./flash.sh build/Debug  # Debug bauen + flashen
```

### Abhängigkeiten prüfen

```bash
./setup.sh
```

## Alle Befehle auf einen Blick

| Befehl | Beschreibung |
|---|---|
| `cmake --preset Release` | Release konfigurieren (`-O2`) |
| `cmake --preset Debug` | Debug konfigurieren (`-O0`) |
| `cmake --build build/Release` | Release bauen |
| `cmake --build build/Debug` | Debug bauen |
| `cmake --build build/Release --target flash` | Release bauen + flashen |
| `cmake --build build/Debug --target flash` | Debug bauen + flashen |
| `./flash.sh` | Release bauen + flashen (Kurzform) |
| `./setup.sh` | Prüft ob alle Tools installiert sind |
| `cmake --build build/Release --target clean` | Build-Ordner säubern |

## Projektstruktur

```
Nuc_01_OutputSpeed/
├── CMakeLists.txt                 # Build-Regeln
├── CMakePresets.json              # Debug / Release Presets
├── README.md                      # Diese Datei
├── flash.sh                       # Flash-Script
├── setup.sh                       # Setup-Prüfung
├── cmake/
│   └── gcc-arm-none-eabi.cmake    # ARM GCC Toolchain
├── Core/
│   ├── Src/main.c                 # Hauptprogramm
│   ├── Src/stm32f1xx_it.c         # Interrupts
│   └── Inc/                       # Header
├── Drivers/                       # HAL + CMSIS
├── startup_stm32f103xb.s          # Startup-Code
└── STM32F103XX_FLASH.ld           # Linker-Script
```

## GPIO Pins (NUCLEO-F103RB)

| Pin | Funktion | Label auf Board |
|---|---|---|
| PA5 | GPIO Output | D13 (built-in LED) |

## Hardware

- **Board:** NUCLEO-F103RB
- **MCU:** STM32F103RB (Cortex-M3, 72 MHz)
- **Flash:** 128 KB
- **RAM:** 20 KB
- **Debugger:** Integrierter ST-Link/V2
