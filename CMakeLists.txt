cmake_minimum_required(VERSION 3.10)

# Project configuration
project(simkit VERSION 0.1.0)

# Dependencies
find_package(Boost COMPONENTS timer)

# Compiler configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Introspection
message(STATUS "PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR})

# Gather source files
include_directories(include)
set(SRC_FILES src/main.cpp src/LinearMotionModel.cpp)

# Build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(simkit ${SRC_FILES})
target_link_libraries(simkit ${Boost_TIMER_LIBRARY} pthread)

# Tests
include(CTest)
enable_testing()
add_subdirectory(test)