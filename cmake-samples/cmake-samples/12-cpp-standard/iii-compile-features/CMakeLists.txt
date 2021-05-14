# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project (compile-features)

# Add an executable
add_executable(compile-features main.cpp)

# set the C++ standard to the approriate standard for using auto
target_compile_features(compile-features PUBLIC cxx_auto_type)

# Print the list of known compile features for this version of CMake
message("List of compile features: ${CMAKE_CXX_COMPILE_FEATURES}")
