# Shared Library

- [Introduction](#Introduction)
- [Concepts](#Concepts)

# Introduction

Shows a hello world example which first creates and links a shared library.

This also shows how to create an [alias target](https://cmake.org/cmake/help/v3.12/manual/cmake-buildsystem.7.html#alias-targets).

The files in this tutorial are below:

```
$ tree
.
├── CMakeLists.txt
├── include
│   └── shared
│       └── Hello.h
└── src
    ├── Hello.cpp
    └── main.cpp
```

  * [CMakeLists.txt](CMakeLists.txt) - Contains the CMake commands you wish to run
  * [include/shared/Hello.h](include/shared/Hello.h) - The header file to include
  * [src/Hello.cpp](src/Hello.cpp) - A source file to compile
  * [src/main.cpp](src/main.cpp) - The source file with main

# Concepts

## Adding a Shared Library

As with the previous example on static libraries, the **add_library()** function
is also used to create a shared library from some source files.
This is called as follows:

````
add_library(hello_library SHARED
    src/Hello.cpp
)
````

This will be used to create a shared library with the name **libhello_library.so** with
the sources passed to teh **add_library()** function.

## Alias Target

As the name suggests an [alias targer](https://cmake.org/cmake/help/v3.12/manual/cmake-buildsystem.7.html#alias-targets) is an alternative name for a target that can be used instead of the real target name in read-only contexts.

````
add_library(hello::library ALIAS hello_library)
````

As shown below, this allows you to reference the target using the alias name when linking it against other targets.

## Linking a Shared Library

Linking a shared library is the same as linking a static library. When creating your
executable use the the **target_link_library()** function to point to your library

````
add_executable(hello_binary
    src/main.cpp
)

target_link_libraries(hello_binary
    PRIVATE
        hello::library
)
````

This tells CMake to link the hello_library against the hello_binary executable using the alias target name.

An example of this being called by the linker is

````
/usr/bin/c++ CMakeFiles/hello_binary.dir/src/main.cpp.o -o hello_binary -rdynamic libhello_library.so -Wl,-rpath,/home/matrim/workspace/cmake-examples/01-basic/D-shared-library/build
````

# Building the Example

````
$ mkdir build

$ cd build

$ cmake ..
-- The C compiler identification is GNU xxx
-- The CXX compiler identification is GNU xxx
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Configuring done
-- Generating done
-- Build files have been written to: cmake-examples/04-shared-library/build

$ make
Scanning dependencies of target hello_library
[ 50%] Building CXX object CMakeFiles/hello_library.dir/src/Hello.cpp.o
Linking CXX shared library libhello_library.so
[ 50%] Built target hello_library
Scanning dependencies of target hello_binary
[100%] Building CXX object CMakeFiles/hello_binary.dir/src/main.cpp.o
Linking CXX executable hello_binary
[100%] Built target hello_binary

$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  hello_binary  libhello_library.so  Makefile

$ ./hello_binary
Hello Shared Library!
````
