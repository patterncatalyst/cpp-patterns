# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.12)

# Set the project name
project (hello_headers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Hello.cpp
    src/main.cpp
)

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/include/Hello.h)

# Add an executable with the above sources
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADER_FILES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
