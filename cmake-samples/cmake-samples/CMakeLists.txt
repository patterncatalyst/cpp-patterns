cmake_minimum_required(VERSION 3.12)

project(cmake-samples)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(01-hello-cmake)
add_subdirectory(02-hello-headers)
add_subdirectory(03-static-library)
add_subdirectory(04-shared-library)
add_subdirectory(05-installing)
add_subdirectory(06-build-type)
add_subdirectory(07-compile-flags)
add_subdirectory(08-third-party-library)
add_subdirectory(09-compiling-with-clang)
add_subdirectory(10-building-with-ninja)
add_subdirectory(11-imported-targets)
add_subdirectory(12-cpp-standard)
