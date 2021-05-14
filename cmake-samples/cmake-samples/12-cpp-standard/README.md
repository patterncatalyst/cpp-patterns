# C++ Standard

Since the release of C+\+11 and C++14 a common use case is to invoke the compiler to use these standards. As CMake has evolved, it has added features to make this easier and new versions of CMake have changed how this is achieved.

The following examples show different methods of setting the C++ standard and what versions of CMake they are available from.

The examples include:

  - [common-method](i-common-method) - A simple version that should work with most versions of CMake.
  - [cxx-standard](ii-cxx-standard) -  Using the `CMAKE_CXX_STANDARD` variable.
  - [compile-features](iii-compile-features) - Using the `target_compile_features` function.
