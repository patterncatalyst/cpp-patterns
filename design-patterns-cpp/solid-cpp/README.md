# SOLID Principles

- [Introduction](#Introduction)
- [Directory Structure](#Directory Structure)

# Introduction

Code for the SOLID design principles portion of the C++ Design Patterns Sessions.

# Directory Structure

The files included in this example are:

```
$ tree
.
└── solid-cpp
    ├── CMakeLists.txt
    ├── README.adoc
    ├── solid-boostdi
    │   ├── CMakeLists.txt
    │   ├── di.hpp
    │   └── main.cpp
    ├── solid-isp
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── solid-lsp
    │   ├── CMakeLists.txt
    │   └── main.cpp
    ├── solid-ocp
    │   ├── CMakeLists.txt
    │   └── main.cpp
    └── solid-srp
        ├── CMakeLists.txt
        └── main.cpp
...

```

# Command-Line Build

````
$ cd solid-cpp
````

Run cmake against the CMakeLists.txt.  Assume this is *nix environment and case sensitive.

````
$ cmake CMakeLists.txt
````

When it's done, run make to build the executables.

````
$ make
````