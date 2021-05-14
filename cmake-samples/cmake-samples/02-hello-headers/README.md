# Hello Headers

- [Introduction](#Introduction)
- [Concepts](#Concepts)

# Introduction

Shows a hello world example which uses a different folder for source and include
files.

The files in this tutorial include:

```
02-hello-headers$ tree
.
├── CMakeLists.txt
├── include
│   └── Hello.h
└── src
    ├── Hello.cpp
    └── main.cpp
```

  * [CMakeLists.txt](CMakeLists.txt) - Contains the CMake commands you wish to run.
  * [include/Hello.h](include/Hello.h) - The header file to include.
  * [src/Hello.cpp](src/Hello.cpp) - A source file to compile.
  * [src/main.cpp](src/main.cpp) - The source file with main.


# Concepts

## Directory Paths

CMake syntax specifies a number of [variables](https://cmake.org/Wiki/CMake_Useful_Variables)
which can be used to help find useful directories in your project or source tree.
Some of these include:


| **Variable** | **Info** |
| --- | --- |
CMAKE_SOURCE_DIR | The root source directory
CMAKE_CURRENT_SOURCE_DIR | The current source directory if using sub-projects and directories.
PROJECT_SOURCE_DIR | The source directory of the current cmake project.
CMAKE_BINARY_DIR | The root binary / build directory. This is the directory where you ran the cmake command.
CMAKE_CURRENT_BINARY_DIR | The build directory you are currently in.
PROJECT_BINARY_DIR | The build directory for the current project.

## Source Files Variable

Creating a variable which includes the source files allows you to be
clearer about these files and easily add them to multiple commands, for example,
the +add_executable()+ function.


### Create a sources variable
````
# Link to all cpp files to compile
set(SOURCES
    src/Hello.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
````

**NOTE**
````
An alternative to setting specific file names in the +SOURCES+ variable is
to use a GLOB command to find files using wildcard pattern matching.

file(GLOB SOURCES "src/*.cpp")
````

**TIP**
````
For modern CMake it is NOT recommended to use a variable for sources. Insead it is 
typical to directly declare the sources in the add_xxx function.

This is particularly important for glob commands which may not always show you the
correct results if you add a new source file.
````

## Including Directories

When you have different include folders, you can make your compiler aware of them using the
`target_include_directories()`.
CMake [target include directories](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html). 
When compiling this target this will add these directories to the compiler with the -I flag e.g. `-I/directory/path`

````
target_include_directories(target
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
````

The **PRIVATE** identifier specifies the scope of the include. 
This is important for libraries and is explained in the next example.
More details on the function is available
[here](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html).

# Building the Example

## Standard Output

The standard output from building this example is presented below.

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
-- Build files have been written to: /cmake-examples/hello_headers/build

$ make
Scanning dependencies of target hello_headers
[ 50%] Building CXX object CMakeFiles/hello_headers.dir/src/Hello.cpp.o
[100%] Building CXX object CMakeFiles/hello_headers.dir/src/main.cpp.o
Linking CXX executable hello_headers
[100%] Built target hello_headers

$ ./hello_headers
Hello Headers!
````


## Verbose Output

In the previous examples, when running the make command the output only
shows the status of the build. To see the full output for debugging
purposes you can add `VERBOSE=1` flag when running make.

The VERBOSE output is show below, and a examination of the output shows
the include directories being added to the c++ compiler command.

````
$ make clean

$ make VERBOSE=1
````

## Additional Notes

Following taken from [StackOverflow](https://stackoverflow.com/questions/13703647/how-to-properly-add-include-directories-with-cmake).

CMake is more like a script language if comparing it with other ways to create Makefile (e.g. make or qmake).

There are no such thing like a "proper way" if looking in various open-source projects how people include directories. 

But there are two ways to do it.

Crude *include_directories* will append a directory to the current project and all other descendant projects which you will append via a series of add_subdirectory commands. 

A more elegant way is with *target_include_directories*. It allows to append a directory for a specific project/target without (maybe) unnecessary inheritance or clashing of various include directories. Also allow to perform even a subtle configuration and append one of the following markers for this command.

* PRIVATE - use only for this specified build target

* PUBLIC - use it for specified target and for targets which links with this project

* INTERFACE -- use it only for targets which links with the current project

Both commands allow to mark a directory as *SYSTEM* to give a hint that it is not your business that specified directories will contain warnings.

A similar answer is with other pairs of commands:
* target_compile_definitions/add_definitions
* target_compile_options/CMAKE_C_FLAGS
