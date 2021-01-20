cmake_minimum_required(VERSION 3.0.0)

# Definitions
set(PROJECT_NAME_STR simkit-cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Project configuration
project(${PROJECT_NAME_STR})

# Compiler configuration
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Testing
include(CTest)
enable_testing()

# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)

# Gather all sources except the main entry point
file(GLOB_RECURSE INC_FILES src/*/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*/*.cpp)

# Build
set(SOURCE_FILES src/main.cpp ${INC_FILES} ${SRC_FILES})
add_executable(simkit ${SOURCE_FILES})

# CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
