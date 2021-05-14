cmake_minimum_required(VERSION 3.12)
project(pimplidiom)

set(CMAKE_CXX_STANDARD 17)

# Structural Design Patterns
add_executable(pimplidiom
        main.cpp
        Person.h
        Person.cpp)

