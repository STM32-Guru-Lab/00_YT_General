# STM32-Guru — 00_YT_General

Companion code repository for the [STM32-Guru](https://www.youtube.com/@STM32-Guru) YouTube channel.

This repository contains embedded C projects for **STM32F103** (Cortex-M3) using **CMSIS-only** register access — no HAL, no LL. The goal is to understand exactly what happens on the silicon level.

---

## Repository Structure

```
00_YT_General/
├── Blp_00_Empty_CMSIS/        # Bluepill (STM32F103C6T6) — CMSIS-only base project
├── Nuc_00_Empty_CMSIS/        # Nucleo (STM32F103RB)     — CMSIS-only base project
├── 01_Nuc_Output_Speed_GPIO/  # GPIO Output Speed register analysis
├── Nuc_01_OutputSpeed/        # GPIO toggle frequency measurement
├── Nuc_02_Compiler_Optimierung/ # Compiler optimization comparison (O0/Og/O1/Os/O2)
└── Bsp/
    └── blog/                  # Blog articles (Hugo content)
        ├── stm32-hal-vs-cmsis-gpio-toggle/
        ├── stm32-gpio-output-speed/
        ├── stm32-gpio-cpu-headroom/
        └── stm32-gpio-compiler-optimizations/
```

### Project Details

| Project | Target MCU | Description |
|---------|-----------|-------------|
| [`Blp_00_Empty_CMSIS`](./Blp_00_Empty_CMSIS) | STM32F103C6T6 (64 KB Flash) | **CMSIS-only** base project for Bluepill. Minimal `main.c` + `clock.c`/`clock.h` with direct register access (HSI 8 MHz, no PLL). |
| [`Nuc_00_Empty_CMSIS`](./Nuc_00_Empty_CMSIS) | STM32F103RB (128 KB Flash) | **CMSIS-only** base project for Nucleo-64. Same architecture as Blp variant, adapted for the larger flash variant. |
| [`01_Nuc_Output_Speed_GPIO`](./01_Nuc_Output_Speed_GPIO) | STM32F103RB | GPIO output speed register (OSPEEDR) analysis. Demonstrates that speed settings affect **slew rate**, not toggle frequency. |
| [`Nuc_01_OutputSpeed`](./Nuc_01_OutputSpeed) | STM32F103RB | GPIO toggle frequency measurement with HAL, ODR-XOR, and BSRR methods at different optimization levels. |
| [`Nuc_02_Compiler_Optimierung`](./Nuc_02_Compiler_Optimierung) | STM32F103RB | Systematic comparison of all GCC optimization levels (-O0, -Og, -O1, -Os, -O2). Disassembly analysis included. |

### Blog Articles

| Article | Topic |
|---------|-------|
| [HAL vs CMSIS GPIO Toggle](./Bsp/blog/stm32-hal-vs-cmsis-gpio-toggle) | Performance comparison of `HAL_GPIO_TogglePin()` vs ODR-XOR vs BSRR |
| [GPIO Output Speed](./Bsp/blog/stm32-gpio-output-speed) | What the OSPEEDR register actually does (slew rate, not frequency) |
| [CPU Headroom](./Bsp/blog/stm32-gpio-cpu-headroom) | The perspective shift: measuring CPU reserve, not peak frequency |
| [Compiler Optimizations](./Bsp/blog/stm32-gpio-compiler-optimizations) | How -O0 through -O2 affect generated assembly and toggle rates |

---

## Prerequisites

- **ARM GCC Toolchain** 14.3.1 (included with STM32CubeIDE 2.1.0)
  - Path: `/opt/st/stm32cubeide_2.1.0/plugins/.../tools/bin/arm-none-eabi-gcc`
- **CMake** ≥ 3.22
- **Make** (Unix Makefiles)
- **OpenOCD** (for flashing, optional)

---

## Build & Flash

Each project uses CMake presets. Example for the Bluepill base project:

```bash
cd Blp_00_Empty_CMSIS

# Configure (Debug)
cmake --preset Debug

# Build
cmake --build --preset Debug

# Configure & build Release
cmake --preset Release
cmake --build --preset Release
```

Build results (empty CMSIS base projects):

| Config | FLASH  | RAM    |
|--------|--------|--------|
| Debug  | 984 B  | 1568 B |
| Release| ~740 B | 1568 B |

### Flash via OpenOCD

```bash
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
  -c "program build/Debug/Blp_00_Empty_CMSIS.elf verify reset exit"
```

---

## Key Design Decisions

- **CMSIS-only**: All projects use direct register access via `stm32f103x*.h` CMSIS headers. No HAL, no LL — full control and transparency.
- **`clock.c`/`clock.h`**: Clock configuration is extracted into a separate module for reusability. Currently configured for HSI 8 MHz. Ready for future HSE/PLL extensions.
- **CMake, not CubeIDE**: Build system is pure CMake with presets. No IDE dependency, CI-friendly.

---

## License

STM32CubeMX-generated code is licensed under the terms of the original ST license. User-contributed code is available under the MIT License unless otherwise noted.

---

## About

Created and maintained by [STM32-Guru](https://www.youtube.com/@STM32-Guru) — Embedded performance analysis, CMSIS deep dives, and firmware development.
