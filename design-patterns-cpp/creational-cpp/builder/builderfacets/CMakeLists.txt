cmake_minimum_required(VERSION 3.12)
project(builderfacets)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(include)
file(GLOB_RECURSE MYSOURCES src/*.cpp)

add_executable(builderfacets ${MYSOURCES})