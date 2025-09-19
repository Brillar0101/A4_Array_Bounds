cmake_minimum_required(VERSION 3.10)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(array_bounds)

# Include the directory where headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the main executable
add_executable(array_bounds src/main.cpp src/array_bounds.cpp)

# Add the test executable
add_executable(my_test src/array_bounds.cpp tests/test.cpp)

# Include directories for the test target
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Enable testing
enable_testing()

# Register the test executable with CTest
add_test(NAME my_test COMMAND my_test)