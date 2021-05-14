cmake_minimum_required(VERSION 3.12)
project(builder)

set(CMAKE_CXX_STANDARD 17)

# Builder sub projects
add_subdirectory(builder)
add_subdirectory(builderfacets)
add_subdirectory(fluentbuilder)
add_subdirectory(groovystylebuilder)
add_subdirectory(lifewithoutbuilder)