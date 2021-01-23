cmake_minimum_required(VERSION 3.10)

# Project configuration
project(simkit VERSION 0.1.0)

# Compiler configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Introspection
message(STATUS "PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR})

# Gather source files
include_directories(include)
set(SRC_FILES src/main.cpp src/Model.cpp)

# Build
add_executable(simkit ${SRC_FILES})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Tests
include(CTest)
enable_testing()
add_subdirectory(test)