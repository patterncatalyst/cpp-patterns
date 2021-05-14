cmake_minimum_required(VERSION 3.12)

project(shared_library)

############################################################
# Create a library
############################################################

#Generate the shared library from the library sources
add_library(shared_library SHARED
    src/Hello.cpp
)
add_library(hello::library ALIAS shared_library)

target_include_directories(shared_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(shared_binary
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( shared_binary
    PRIVATE 
        hello::library
)
