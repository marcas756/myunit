#!/bin/bash

rm ./build -rf
mkdir -p build/Debug
cmake -E chdir build/Debug cmake -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../myunit


