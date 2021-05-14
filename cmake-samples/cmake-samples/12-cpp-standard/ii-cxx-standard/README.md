# Set C++ Standard

- [Introduction](#Introduction)
- [Concepts](#Concepts)

# Introduction

This example shows how to set the C++ standard using the `CMAKE_CXX_STANDARD` variable. This is available since CMake v3.1

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

## Using CXX_STANDARD property

Setting the [CMAKE_CXX_STANDARD](https://cmake.org/cmake/help/v3.12/variable/CMAKE_CXX_STANDARD.html) variable causes the `CXX_STANDARD` property on all targets. This causes CMake to set the appropriate flag at compile time.


**NOTE**
````
The `CMAKE_CXX_STANDARD` variable falls back to the closest appropriate standard without a failure. For example, if you request `-std=gnu++11` you may end up with `-std=gnu++0x`.

This can result in an unexpected failure at compile time.
````

# Building the Examples

Below is sample output from building this example.

````
$ mkdir build
$ cd build


$ cmake ..
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
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
-- Configuring done
-- Generating done
-- Build files have been written to: /cmake-samples/12-cpp-standard/ii-cxx-standard/build

$ make VERBOSE=1
````
