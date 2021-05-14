cmake_minimum_required(VERSION 3.12)
project(bloom)

set(CMAKE_CXX_STANDARD 17)

# need to install the glew library
# need to install OpenGL
# need to install FreeType
# need to install glm
#If you need to have openssl first in your PATH run:
#echo 'export PATH="/usr/local/opt/openssl/bin:$PATH"' >> ~/.bash_profile

#For compilers to find openssl you may need to set:
#export LDFLAGS="-L/usr/local/opt/openssl/lib"
#export CPPFLAGS="-I/usr/local/opt/openssl/include"

find_package(OpenGL REQUIRED)


# Structural Design Patterns
include_directories(${GLFW_INCLUDE_DIRS})
find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})


# default search dirs
SET(_glm_HEADER_SEARCH_DIRS
        "/usr/include"
        "/usr/local/include")

# check environment variable
SET(_glm_ENV_ROOT_DIR "$ENV{GLM_ROOT_DIR}")

IF(NOT GLM_ROOT_DIR AND _glm_ENV_ROOT_DIR)
    SET(GLM_ROOT_DIR "${_glm_ENV_ROOT_DIR}")
ENDIF(NOT GLM_ROOT_DIR AND _glm_ENV_ROOT_DIR)

# put user specified location at beginning of search
IF(GLM_ROOT_DIR)
    SET(_glm_HEADER_SEARCH_DIRS "${GLM_ROOT_DIR}"
            "${GLM_ROOT_DIR}/include"
            ${_glm_HEADER_SEARCH_DIRS})
ENDIF(GLM_ROOT_DIR)

# locate header
FIND_PATH(GLM_INCLUDE_DIR "glm/glm.hpp"
        PATHS ${_glm_HEADER_SEARCH_DIRS})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLM DEFAULT_MSG
        GLM_INCLUDE_DIR)

IF(GLM_FOUND)
    SET(GLM_INCLUDE_DIRS "${GLM_INCLUDE_DIR}")

    MESSAGE(STATUS "GLM_INCLUDE_DIR = ${GLM_INCLUDE_DIR}")
ENDIF(GLM_FOUND)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

add_executable(bloom
        Area.h
        Area.cpp
        Bloom.cpp
        Console.h
        IBuffer.h
        MenuBar.h
        MenuBar.cpp
        Point4.h
        ShaderUtils.h
        ShaderUtils.cpp
        TextRenderer.h
        TextBuffer.cpp
        TextRenderer.h
        TextRenderer.cpp
        TextureManager.h
        TextureManager.cpp
        Util.h
        Util.cpp
        Viewport.h
        Viewport.cpp
        Window.h
        Window.cpp)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} ${FREETYPE_LIBRARIES})
target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_gl_LIBRARY}
        ${GLUT_LIBRARIES} )

target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})

