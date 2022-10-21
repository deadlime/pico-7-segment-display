cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
set(PICO_SDK_INIT_CMAKE_FILE ${PICO_SDK_PATH}/pico_sdk_init.cmake)
include(${PICO_SDK_INIT_CMAKE_FILE})

project(pico-7-segment-display C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_compile_options(-Wall -Wno-format -Wno-unused-function -Wno-maybe-uninitialized)

add_subdirectory(1_c-only)
add_subdirectory(2_basic-pio)
add_subdirectory(3_advanced-pio)
