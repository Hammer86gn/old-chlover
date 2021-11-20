cmake_minimum_required(VERSION 3.20)
project(chlover-engine)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

include(Module)


add_subdirectory(lib/glad2/cmake)
glad_add_library(glad2 STATIC
    LANGUAGE C
    API gl:core=3.0
    )
add_custom_command(
    TARGET glad2 PRE_BUILD
    COMMAND python3 -m pip install -U -r \"${CMAKE_CURRENT_LIST_DIR}/lib/glad2/requirements.txt\")

add_subdirectory(lib/glfw)
# NOTE TO CHLOE FROM CAE:
# Header files are not sources 
# kthxbye
chlover_module(engine LIBRARY
    INCLUDE include
    DEPENDENCIES glad2 glfw
    DEPENDENCIES_PKG OpenSSL
    SOURCES
    src/util/Hash.cpp src/util/Representation.cpp
    src/asset/Asset.cpp src/core/application/ChloverApplication.cpp
    src/core/application/EntryPoint.cpp
    )

chlover_module(test EXECUTABLE
        INCLUDE test/include
        DEPENDENCIES engine
        SOURCES
        test/src/TestMain.cpp)
