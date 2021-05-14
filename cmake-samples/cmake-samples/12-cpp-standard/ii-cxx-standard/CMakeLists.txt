# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project (cxx-standard)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# Add an executable
add_executable(cxx-standard main.cpp)
