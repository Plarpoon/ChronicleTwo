cmake_minimum_required(VERSION 3.20)
project(chronicletwo NONE)

# PLATFORM picks what is built: PS2 builds and verifies the retail executable
# (ps2/CMakeLists.txt).
set(PLATFORM PS2 CACHE STRING "Platform to build")
set_property(CACHE PLATFORM PROPERTY STRINGS PS2)
if(PLATFORM STREQUAL "PS2")
    add_subdirectory(ps2)
else()
    message(FATAL_ERROR "PLATFORM must be PS2, not ${PLATFORM}")
endif()
