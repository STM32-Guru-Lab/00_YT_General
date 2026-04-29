#!/usr/bin/env bash
# Flash NUCLEO-F103RB via OpenOCD + ST-Link
# Usage: ./flash.sh [build_dir]
# Default: build/Release

set -e

BUILD_DIR="${1:-build/Release}"
PROJECT_NAME="Nuc_01_OutputSpeed"
ELF_FILE="${BUILD_DIR}/${PROJECT_NAME}.elf"

if [ ! -f "${ELF_FILE}" ]; then
    echo "==> Building first..."
    cube-cmake --build "${BUILD_DIR}"
fi

echo "==> Flashing ${ELF_FILE} via OpenOCD..."
openocd -f interface/stlink.cfg \
        -f target/stm32f1x.cfg \
        -c "program ${ELF_FILE} verify reset exit"

echo "==> Done."
