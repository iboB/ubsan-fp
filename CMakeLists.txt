cmake_minimum_required(VERSION 3.10)

project(ubsan-fp)

if(NOT MSVC)
    set(SAN_FLAGS "-fsanitize=address,undefined,leak -pthread -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SAN_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SAN_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SAN_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${SAN_FLAGS}")
endif()
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

