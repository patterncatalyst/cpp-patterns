cmake_minimum_required(VERSION 3.12)

# Set the project name
project (12-cpp-standard)

# set the C++ standard to C++ 11
set(CMAKE_CXX_STANDARD 11)

# Add an executable
add_subdirectory(i-common-method)
add_subdirectory(ii-cxx-standard)
add_subdirectory(iii-compile-features)