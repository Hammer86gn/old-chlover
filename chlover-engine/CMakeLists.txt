cmake_minimum_required(VERSION 3.20)
project(chlover-engine)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

include(Module)

chlover_module(engine LIBRARY
    include/chlover/Chlover.h
    )
