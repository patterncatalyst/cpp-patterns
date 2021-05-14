cmake_minimum_required(VERSION 3.12)
project(proxy)

set(CMAKE_CXX_STANDARD 17)

# Structural Design Patterns
add_subdirectory(communicationProxy)
add_subdirectory(smartPointerProxy)
add_subdirectory(virtualProxy)

