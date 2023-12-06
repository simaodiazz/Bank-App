cmake_minimum_required(
    VERSION 3.16
)

project(
    App
    VERSION 1.0.0
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(
    App
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
