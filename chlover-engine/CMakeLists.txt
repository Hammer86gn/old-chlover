cmake_minimum_required(VERSION 3.20)
project(chlover-engine)

set(CMAKE_CXX_STANDARD 17)

include(Module)

add_subdirectory(lib/glfw)

chlover_module(engine LIBRARY
    INCLUDE include
    DEPENDENCIES glfw
    DEPENDENCIES_PKG OpenSSL
    SOURCES src/asset/Asset.cpp
    )
