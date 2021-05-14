# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project (hello-cmake)

# Add an executable
add_executable(hello-cmake main.cpp)
