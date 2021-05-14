# Basic Examples

The basic examples in this directory show how the setup a CMake project,
set compile flags, create and link executables and libraries, and install them.

The examples included are

  - [hello-cmake](01-hello-cmake) - A hello world example.
  - [hello-headers](02-hello-headers) - A slightly more complicated hello world example, using seperate source and include folders.
  - [static-library](03-static-library) - An example using a static library.
  - [shared-library](04-shared-library) - An example using a shared library.
  - [installing](05-installing) - Shows how to create a 'make install' target that will install binaries and libraries.
  - [build-type](06-build-type) - An example showing how to set a default build and optimization flags for your project.
  - [compile-flags](07-compile-flags) - Shows how to set additional compile flags.
  - [third-party-library](08-third-party-library) - Shows an example of how to link third party libraries.
  - [compiling-with-clang](09-compiling-with-clang) - An example of invoking the clang compiler.
  - [building-with-ninja](10-building-with-ninja) - Shows how to generate ninja build files
  - [imported-targets](11-imported-targets) - Shows how to link boost using the new imported targets
  - [cpp-standard](12-cpp-standard) - Shows various methods to set the C++ standard
  
# NOTES

If you are on the Mac and upgraded the OS e.g. Mavericks, you will have to re-install the command-line tools.

This may cause various unusual issues such as: error finding wchar.h in iostream.  There are several interesting workarounds
out there. Before you do anything else, try deleting the *CMakeCache* file first.  Then reload the project if you're in CLion.
This will usually clear things up.
