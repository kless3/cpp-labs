cmake_minimum_required(VERSION 3.28)
project(laba6)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba6 src/main.cpp
        include/Array.h
        src/Array.cpp
        include/Menu.h
        src/Menu.cpp)
