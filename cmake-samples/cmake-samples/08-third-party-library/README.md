# Including Third Party Library

- [Introduction](#Introduction)
- [Requirements](#Requirements)
- [Concepts](#Concepts)

# Introduction

Nearly all non-trivial projects will have a requirement for including third party
libraries, headers, or programs. 

CMake has support for finding the path to these tools using the `find_package()` function. 
This will search for CMake modules in the format "FindXXX.cmake" from the list of folders in `CMAKE_MODULE_PATH`. On linux the
default search path will include `/usr/share/cmake/Modules`. On my system this includes support for approximately 142 common third party libraries.

The files in this tutorial are below:

```
$ tree
.
├── CMakeLists.txt
├── main.cpp
```

  * [CMakeLists.txt](CMakeLists.txt) - Contains the CMake commands you wish to run
  * [main.cpp](main.cpp) - The source file with main

# Requirements

This example requires the boost libraries to be installed in a default system
location.

# Concepts

## Finding a Package

As mentioned above the `find_package()` function will search for CMake modules in the formant
"FindXXX.cmake" from the list of folders in `CMAKE_MODULE_PATH`. The exact
format of the arguments to `find_package` will depend on the module you are looking
for. This is typically documented at the top of the `FindXXX.cmake` file.

A basic example of finding boost is below:

````
find_package(Boost REQUIRED COMPONENTS filesystem system)
````

We can also look for a specific package if we have multiple installed:
````
find_package(Boost 1.64.1 REQUIRED COMPONENTS filesystem system)
````

The arguments are:

  * Boost - Name of the library. This is part of used to find the module file FindBoost.cmake
  * 1.64.1 - The minimum version of boost to find
  * REQUIRED - Tells the module that this is required and to fail it it cannot be found
  * COMPONENTS - The list of libraries to find.

Boost includes can take more arguments and also make use of other variables.
More complex setups are provided in later examples.


## Checking if the package is found

Most included packages will set a variable `XXX_FOUND`, which can used to check
if the package is available on the system.

In this example the variable is `Boost_FOUND`:

````
if(Boost_FOUND)
    message ("boost found")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()
````

## Exported Variables

After a package is found it will often export variables which can inform the user
where to find the library, header, or executable files. Similar to the `XXX_FOUND`
variable, these are package specific and are typically documented at the top of the
`FindXXX.cmake` file.

The variables exported in this example include:

  * `Boost_INCLUDE_DIRS` - The path to the boost header files.

In some cases you can also check these variables by examining the cache using
ccmake or cmake-gui.

## Alias / Imported targets

Most modern CMake libraries [export](https://cmake.org/cmake/help/v3.12/prop_tgt/IMPORTED.html#prop_tgt:IMPORTED) **ALIAS** targets in their module files. 
The benefit of imported targets are that they can also populate include directories and linked libraries.

For example, starting from v3.12+ of CMake, the
Boost module supports this. Similar to using your own **ALIAS** target for libraries, an **ALIAS** in a module can make referencing found targets eaiser.

In the case of Boost, all targets are exported using the `Boost::` identifier and then the name 
of the subsystem. For example you can use:

  * `Boost::boost` for header only libraries
  * `Boost::system` for the boost system library.
  * `Boost::filesystem` for filesystem library.

As with your own targets, these targets include their dependencies, so linking against
`Boost::filesystem` will automatically add `Boost::boost` and `Boost::system` dependencies.

To link against an imported target you can use the following:

````
  target_link_libraries( third_party_include
      PRIVATE
          Boost::filesystem
  )
````

## Non-alias targets

While most modern libraries use imported targets, not all modules have been updated. In the
case where a library hasn't been updated you will often find the following variables available:

  * xxx_INCLUDE_DIRS - A variable pointing to the include directory for the library.
  * xxx_LIBRARY - A variable pointing to the library path.

These can then be added to your **target_include_directories** and **target_link_libraries** as:

````
# Include the boost headers
target_include_directories( third_party_include
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
````

# Building the Example

````
$ mkdir build

$ cd build/

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
-- Boost version: 1.54.0
-- Found the following Boost libraries:
--   filesystem
--   system
boost found
-- Configuring done
-- Generating done
-- Build files have been written to: cmake-examples/08-third-party-library/build

$ make
Scanning dependencies of target third_party_include
[100%] Building CXX object CMakeFiles/third_party_include.dir/main.cpp.o
Linking CXX executable third_party_include
Hello Third Party Include!
Path is not relative
$ cmake ..
-- The C compiler identification is GNU 
-- The CXX compiler identification is GNU
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Boost version: 1.54.0
-- Found the following Boost libraries:
--   filesystem
--   system
boost found
-- Configuring done
-- Generating done
-- Build files have been written to: cmake-examples/08-third-party-library/build

$ make
Scanning dependencies of target third_party_include
[100%] Building CXX object CMakeFiles/third_party_include.dir/main.cpp.o
Linking CXX executable third_party_include
[100%] Built target third_party_include

$ ./third_party_include
Hello Third Party Include!
Path is not relative

````
