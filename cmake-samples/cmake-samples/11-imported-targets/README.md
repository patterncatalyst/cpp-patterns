# Imported Targets

- [Introduction](#Introduction)
- [Requirements](#Requirements)
- [Concepts](#Concepts)

# Introduction

As previously mentioned in the [third party library](../08-third-party-library), newer
versions of CMake allow you to link third party libraries using [imported](https://cmake.org/cmake/help/v3.12/prop_tgt/IMPORTED.html#prop_tgt:IMPORTED) **ALIAS** targets.

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

This example requires the following:

  * CMake v3.12
  * The boost libraries to be installed in a default system location. 

# Concepts

## Imported Target

Imported targets are read-only targets that are exported by FindXXX modules. 

To include boost filesystem you can do the following:

````
  target_link_libraries( imported_targets
      PRIVATE
          Boost::filesystem
  )
````

This will automatically link the Boost::filesystem and Boost::system libraries while also including the
Boost include directories.

# Building the Example

````
$ mkdir build

$ cd build/

$ cmake ..
-- The C compiler identification is GNU 
-- The CXX compiler identification is GNU
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Boost version: 1.58.0
-- Found the following Boost libraries:
--   filesystem
--   system
boost found
-- Configuring done
-- Generating done
-- Build files have been written to: /cmake-samples/11-imported-targets/build

$ make
Scanning dependencies of target imported_targets
[ 50%] Building CXX object CMakeFiles/imported_targets.dir/main.cpp.o
[100%] Linking CXX executable imported_targets
[100%] Built target imported_targets


$ ./imported_targets
Hello Third Party Include!
Path is not relative
````
