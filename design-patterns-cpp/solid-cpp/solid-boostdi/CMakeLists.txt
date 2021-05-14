cmake_minimum_required(VERSION 3.12)
project(solid_boostdi)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------
# Boost can be found if installed on the OS and in the path
# ------------------------------------------------------------
find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

# ------------------------------------------------------------
# Enable or disable dynamic linking
# ------------------------------------------------------------
set (Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set (Boost_USE_MULTITHREAD ON)  # enable multithreading

# ------------------------------------------------------------
# Include the desired components
# ------------------------------------------------------------
find_package (Boost COMPONENTS REQUIRED chrono filesystem)

# ------------------------------------------------------------
# Include targeted libraries if desired
# target_link_libraries (my_target my_library another_library)
# ------------------------------------------------------------


add_executable(solid_boostdi main.cpp)