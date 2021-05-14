cmake_minimum_required(VERSION 3.12)
project(communicationProxy)

set(CMAKE_CXX_STANDARD 17)

find_package(cpprestsdk REQUIRED)

find_package(Boost REQUIRED program_options regex date_time system filesystem thread graph)
include_directories(${BOOST_INCLUDE_DIRS})
message("boost lib: ${Boost_LIBRARIES}, inc:${Boost_INCLUDE_DIR}")


# Structural Design Patterns
add_executable(communicationProxy communicationProxy.cpp)
target_link_libraries(${PROJECT_NAME}  PRIVATE cpprestsdk::cpprest ${Boost_LIBRARIES})

