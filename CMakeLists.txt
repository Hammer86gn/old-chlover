cmake_minimum_required(VERSION 3.20)
project(Chlover)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_subdirectory(chlover-engine)
add_subdirectory(chlover-editor)