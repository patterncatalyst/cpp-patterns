cmake_minimum_required(VERSION 3.12)
project(boostserialization)

set(CMAKE_CXX_STANDARD 17)

# ------------------------------------------------------------
# Boost can be found if installed on the OS and in the path
# ------------------------------------------------------------
find_package(Boost COMPONENTS REQUIRED chrono filesystem serialization program_options)
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
# NOTE: Yes, this should probably all go into the conditional
#       above BOOST_FOUND
# ------------------------------------------------------------
add_library(boost::serialization INTERFACE IMPORTED)
set_target_properties(boost::serialization PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${Boost_SERIALIZATION_LIBRARIES}")

# ------------------------------------------------------------
# Create the executable and link in the Boost library
# ------------------------------------------------------------
add_executable(boostserialization Serialization.cpp)

TARGET_LINK_LIBRARIES( boostserialization LINK_PUBLIC ${Boost_LIBRARIES} )
