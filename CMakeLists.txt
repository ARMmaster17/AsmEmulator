cmake_minimum_required(VERSION 2.8)
project(AsmEmulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES source/AsmEmulator.cpp source/GEN_Register.cpp source/Opcodes.cpp source/RAM.cpp source/SFLAG_Register.cpp source/stdafx.cpp source/StringHelpers.cpp include/targetver.h)
add_executable(AsmEmulator ${SOURCE_FILES})