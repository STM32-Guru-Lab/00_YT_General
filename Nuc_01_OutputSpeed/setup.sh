#!/usr/bin/env bash
# Setup script: Prüft alle Abhängigkeiten für Nuc_01_OutputSpeed
# Aufruf: ./setup.sh

set -e

echo "=== Nuc_01_OutputSpeed - Setup Check ==="
echo ""

# Prüfe cube-cmake (STM32-CMake-Wrapper aus VS Code Extension)
if command -v cube-cmake &>/dev/null; then
    echo "✅ cube-cmake: gefunden (CMake in STM32CubeIDE)"
else
    echo "❌ cube-cmake: nicht gefunden. STM32CubeIDE VS Code Extension installieren?"
    echo "   Fallback: Standard cmake verwenden?"
fi

# Prüfe make
if command -v make &>/dev/null; then
    echo "✅ make:     $(make --version | head -1)"
else
    echo "❌ make:     nicht gefunden. Installiere mit: sudo apt install build-essential"
fi

# Prüfe openocd
if command -v openocd &>/dev/null; then
    echo "✅ openocd:  $(openocd --version | head -1)"
else
    echo "❌ openocd:  nicht gefunden. Installiere mit: sudo apt install openocd"
fi

# Prüfe ARM-Toolchain
TOOLCHAIN="/opt/st/stm32cubeide_2.1.0/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.14.3.rel1.linux64_1.0.100.202602081740/tools/bin/arm-none-eabi-gcc"
if [ -f "${TOOLCHAIN}" ]; then
    echo "✅ arm-gcc:  ${TOOLCHAIN}"
    echo "   Version:  $(${TOOLCHAIN} --version | head -1)"
else
    echo "❌ arm-gcc:  nicht gefunden unter ${TOOLCHAIN}"
    echo "   STM32CubeIDE installiert?"
fi

# Prüfe cube-cmake
if command -v cube-cmake &>/dev/null; then
    echo "✅ cube-cmake: gefunden"
else
    echo "❌ cube-cmake: nicht im PATH (VS Code STM32 Extension nötig)"
fi

echo ""
echo "=== Fertig ==="
