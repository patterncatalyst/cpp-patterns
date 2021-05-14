# C++ Standard Common Method

- [Introduction](#Introduction)
- [Concepts](#Concepts)

# Introduction

This example shows a common method to set the C++ Standard. This can be used with most versions of CMake. However, if you are targeting a recent version of CMake there are more convenient methods available.

The files in this tutorial are below:

```
A-hello-cmake$ tree
.
├── CMakeLists.txt
├── main.cpp
```

  * [CMakeLists.txt](CMakeLists.txt) - Contains the CMake commands you wish to run
  * [main.cpp](main.cpp) - A simple "Hello World" cpp file targeting C++11.

# Concepts

## Checking Compile flags

CMake has support for attempting to compile a program with any flags you pass into the function `CMAKE_CXX_COMPILER_FLAG`. The result is then stored in a variable that you pass in.

For example:

````
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
````

This example will attempt to compile a program with the flag `=std=c++11` and store the result in the variable `COMPILER_SUPPORTS_CXX11`.

The line `include(CheckCXXCompilerFlag)` tells CMake to include this function to make it available for use.

## Adding the flag

Once you have determined if the compile supports a flag, you can then use the [standard cmake methods](../../07-compile-flags/) to add this flag to a target. In this example we use the `CMAKE_CXX_FLAGS` to propagate the flag to all targets .

````
if(COMPILER_SUPPORTS_CXX11)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
````

The above example only checks for the gcc version of the compile flags and supports fallback from C+\+11 to the pre-standardisation C+\+0x flag. In real usage you may want to check for C++14, or add support for different methods of setting the compile, e.g. `-std=gnu++11`

# Building the Examples

Below is sample output from building this example.

````
$ mkdir build
$ cd build

$ cmake ..
-- The C compiler identification is GNU 4.8.4
-- The CXX compiler identification is GNU 4.8.4
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Performing Test COMPILER_SUPPORTS_CXX11
-- Performing Test COMPILER_SUPPORTS_CXX11 - Success
-- Performing Test COMPILER_SUPPORTS_CXX0X
-- Performing Test COMPILER_SUPPORTS_CXX0X - Success
-- Configuring done
-- Generating done
-- Build files have been written to: cmake-samples/12-cpp-standard/i-common-method/build

$ make VERBOSE=1
````
