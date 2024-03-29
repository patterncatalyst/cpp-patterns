# Static Library

- [Introduction](#Introduction)
- [Concepts](#Concepts)

# Introduction

Shows a hello world example which first creates and links a static library. This is a 
simplified example showing the library and binary in the same folder. Typically
these would be in sub-projects as described in section [sub-projects](../../sub-projects)

The files in this tutorial are below:

```
$ tree
.
├── CMakeLists.txt
├── include
│   └── static
│       └── Hello.h
└── src
    ├── Hello.cpp
    └── main.cpp
```

  * [CMakeLists.txt](CMakeLists.txt) - Contains the CMake commands you wish to run
  * [include/static/Hello.h](include/static/Hello.h) - The header file to include
  * [src/Hello.cpp](src/Hello.cpp) - A source file to compile
  * [src/main.cpp](src/main.cpp) - The source file with main


# Concepts

## Adding a Static Library

The `add_library()` function is used to create a library from some source files.
This is called as follows:

````
add_library(hello_library STATIC 
    src/Hello.cpp
)
````

This will be used to create a static library with the name `libhello_library.a` with
the sources in the `add_library` call.

<b>NOTE</b>
````
As mentioned in the prevoius example, we pass the source files directly to the
add_library call, as recommended for modern CMake.
````

## Populating Including Directories

In this example, we include directories in the library using the `target_include_directories()` function with the scope set to `PUBLIC`.

````
target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)
````

This will cause the included directory used in the following places:

* When compiling the library
* When compiling any additional target that links the library.

The meaning of scopes are:

* **PRIVATE** - the directory is added to this target's include directories
* <b>INTERFACE</b> - the directory is added to the include directores for any targets that link this library.
* <b>PUBLIC</b> - As above, it is included int his library and also any targets that link this library.


<b>TIP</b>
````
For public headers it is often a good idea to have your include folder be "namespaced"
with sub-directories. 

The directory passed to target_include_directories will be the root of your 
include directory tree and your C++ files should include the path from there to your header.
````

For this example you can see that we do it as follows:
````
#include "static/Hello.h"
````

Using this method means that there is less chance of header filename clashes when
you use multiple libraries in your project. 

## Linking a Library

When creating an executable that will use your library you must tell the compiler
about the library. This can be done using the **target_link_library()** function.

````
add_executable(hello_binary 
    src/main.cpp
)

target_link_libraries( hello_binary
    PRIVATE  
        hello_library
)
````

This tells CMake to link the hello_library against the hello_binary executable
during link time. It will also propogate any include directries with **PUBLIC** or **INTERFACE** scope
 from the linked library target.

An example of this being called by the compiler is

```
/usr/bin/c++ CMakeFiles/hello_binary.dir/src/main.cpp.o -o hello_binary -rdynamic libhello_library.a
```


# Building the Example

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
-- Configuring done
-- Generating done
-- Build files have been written to: static-library/build

$ make
Scanning dependencies of target hello_library
[ 50%] Building CXX object CMakeFiles/hello_library.dir/src/Hello.cpp.o
Linking CXX static library libhello_library.a
[ 50%] Built target hello_library
Scanning dependencies of target hello_binary
[100%] Building CXX object CMakeFiles/hello_binary.dir/src/main.cpp.o
Linking CXX executable hello_binary
[100%] Built target hello_binary

$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  hello_binary  libhello_library.a  Makefile

$ ./hello_binary
Hello Static Library!
````
