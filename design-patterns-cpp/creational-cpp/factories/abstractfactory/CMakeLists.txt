cmake_minimum_required(VERSION 3.12)
project(abstractfactory)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(include)
file(GLOB SOURCES src/*.cpp)

add_executable(abstractfactory ${SOURCES})
