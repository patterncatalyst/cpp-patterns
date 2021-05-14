cmake_minimum_required(VERSION 3.12)
project(factories)

set(CMAKE_CXX_STANDARD 17)

# Factories sub projects
add_subdirectory(abstractfactory)
add_subdirectory(factory)
add_subdirectory(factorymethod)
add_subdirectory(functionalfactory)
add_subdirectory(innerfactory)
add_subdirectory(pointexample)
