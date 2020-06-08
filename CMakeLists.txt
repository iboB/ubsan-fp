cmake_minimum_required(VERSION 3.10)

project(ubsan-fp)

add_library(core SHARED
    corelib.cpp
    corelib.hpp
)

add_library(otherlib SHARED
    otherlib.cpp
    otherlib.hpp
)

target_link_libraries(otherlib PUBLIC core)

add_executable(executable
    executable.cpp
)

target_link_libraries(executable PUBLIC otherlib)
