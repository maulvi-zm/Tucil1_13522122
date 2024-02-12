# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(BreachProtocolSolver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set source directory
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

# Add executable target
add_executable(BreachProtocolSolver
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/IO/io.cpp
    ${SRC_DIR}/Solver/solver.cpp
    ${SRC_DIR}/Utils/utils.cpp
)

# Include directories
target_include_directories(BreachProtocolSolver PUBLIC
    ${SRC_DIR}/IO
    ${SRC_DIR}/Data-Structure
    ${SRC_DIR}/Solver
    ${SRC_DIR}/Utils
)

