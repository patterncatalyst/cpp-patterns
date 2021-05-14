# Development Environment

- [Introduction](#Introduction)
- [Projects](#Projects)
- [Concepts](#Concepts)
- [Requirements](#Requirements)
- [Other Links](#Links)

# Introduction

This project contains examples for CMake, development environment setup, Modern C++ samples and using CLion.

# Projects

* CMake Samples
    
    * [CMake Samples](cmake-samples)
    * [Design Patterns](design-patterns-cpp)

# Concepts

[CMake](https://cmake.org/) is a cross-platform open-source meta-build system which
can build, test and package software. It can be used to support multiple native build environments including
make, Apple's xcode, Microsoft Visual Studio and Ninja.

This repository includes some example modern CMake configurations which have picked up
when exploring it's usage for various projects. The examples are laid out in a tutorial like format.
The first examples are very basic and slowly increase in complexity drawing on previous examples to show
more complex use cases.  In the [samples](cmake-samples) section, there are CMake and Modern C++ examples.

These examples have been tested on Ubuntu 18.04 but should work under any Linux system that supports CMake v3.12+.

Most of the CMake examples have also been tested on Mac OSX but, you may have to do some work to update them for that
platform.

None of them have been tested on Windows with Cygwin, MinGW or the Windows 10 Subsystem for Linux.  However, they should work for the most part with few modifications.

This branch works with the CMake version 3.12 onwards. 

Even though this repository is on Bitbucket, the original intent was to also make it work with Github and [Travis](https://travis-ci.org/).

# Requirements

The basic requirements for most examples are:

* CMake v3.12+
* A C++ compiler LLVM (clang) or gcc (defaults to gcc)
* make
* CDash

## Installation on Ubuntu

The easiest way to install on Ubuntu is as follows:

````
$ sudo apt-get install build-essential
$ sudo apt-get install cmake
````

Some specific examples may require other tools including:

* [boost](http://www.boost.org/)

  $ sudo apt-get libboost-all-dev

* [protobuf](https://github.com/google/protobuf)

  $ sudo apt-get install libprotobuf-dev
  $ sudo apt-get install protobuf-compiler

* [cppcheck](http://cppcheck.sourceforge.net/)

  $ sudo apt-get install cppcheck

* [clang](http://clang.llvm.org/)

  $ sudo apt-get install clang

* [ninja](https://ninja-build.org/)

  $ sudo apt-get install ninja-build

## Docker

Docker containers with all requirements and various versions of CMake are generated to help make testing the examples easier. 

# Links

There are many CMake tutorials and examples online.

  * [Modern CMake Slides](http://www.kdab.com/~stephen/moderncmake.pdf)
  * [rix0r Modern CMake Blog](https://rix0r.nl/blog/2015/08/13/cmake-guide/)
  * [Official CMake Tutorial](https://cmake.org/cmake-tutorial/)
  * [Official CMake Wiki](https://cmake.org/Wiki/Main_Page)
  * [CMake Useful Variables](https://cmake.org/Wiki/CMake_Useful_Variables)
  * [Derek Molloy - Intro to CMake](http://derekmolloy.ie/hello-world-introductions-to-cmake/)
  * [Modular C++ Projects](http://techminded.net/blog/modular-c-projects-with-cmake.html)
  * [Common CMake Anti-Patterns](http://voices.canonical.com/jussi.pakkanen/2013/03/26/a-list-of-common-cmake-antipatterns/)
  * [John Lamp - CMake Tutorial](https://www.johnlamp.net/cmake-tutorial.html)
  * [Appveyor Official Site](https://www.appveyor.com/)
  * [C++ Reference](https://en.cppreference.com/w/)
  * [git](https://www.atlassian.com/git/tutorials/setting-up-a-repository/git-clone)
  * [git changes](https://www.atlassian.com/git/tutorials/undoing-changes)
  * [virtualenvwrapper](https://virtualenvwrapper.readthedocs.io/en/latest/)
  * [deploy python](https://www.nylas.com/blog/packaging-deploying-python/)
