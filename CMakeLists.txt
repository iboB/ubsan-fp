cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ubsan-fp)

if(NOT MSVC)
    set(SAN_FLAGS "-fsanitize=address,undefined -pthread -g -fvisibility=hidden")
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

