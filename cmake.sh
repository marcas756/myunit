#!/bin/bash

rm ./build -rf
mkdir -p build/Debug
mkdir -p build/C64
cmake -E chdir build/Debug cmake -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../myunit
cmake -E chdir build/C64 cmake -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../../cc65-toolchain.cmake ../../myunit

	