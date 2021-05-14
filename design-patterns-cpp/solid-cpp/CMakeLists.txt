cmake_minimum_required(VERSION 3.12)
project(solid-cpp)

set(CMAKE_CXX_STANDARD 17)

# SOLID
add_subdirectory(solid-ocp)
add_subdirectory(solid-lsp)
add_subdirectory(solid-isp)
add_subdirectory(solid-boostdi)
add_subdirectory(solid-srp)

