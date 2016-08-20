cmake_minimum_required(VERSION 2.8)
project(AsmEmulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES ./AsmEmulator/AsmEmulator.cpp ./AsmEmulator/GEN_Register.cpp ./AsmEmulator/Opcodes.cpp ./AsmEmulator/RAM.cpp ./AsmEmulator/SFLAG_Register.cpp ./AsmEmulator/stdafx.cpp ./AsmEmulator/StringHelpers.cpp ./AsmEmulator/targetver.h)
add_executable(AsmEmulator ${SOURCE_FILES})