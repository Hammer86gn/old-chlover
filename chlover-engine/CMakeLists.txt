cmake_minimum_required(VERSION 3.20)
project(chlover-engine)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

include(Module)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad2/cmake)

glad_add_library(glad2 STATIC 
    LANGUAGE C
    API gl:core=3.0
)

# NOTE TO CHLOE FROM CAE:
# Header files are not sources 
# kthxbye
chlover_module(engine LIBRARY
    INCLUDE include
    DEPENDENCIES glfw glad2
    DEPENDENCIES_PKG OpenSSL
    SOURCES src/asset/Asset.cpp
    )
