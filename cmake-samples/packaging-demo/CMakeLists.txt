cmake_minimum_required(VERSION 3.12)
project(packaging-demo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        src/hello.cpp
        src/main.cpp
        )

# Add an executable with the above sources
#add_executable(packaging-demo ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
#target_include_directories(packaging-demo PRIVATE ${PROJECT_SOURCE_DIR}/include)