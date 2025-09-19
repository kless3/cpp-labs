cmake_minimum_required(VERSION 3.28)
project(laba1)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba1 src/main.cpp
        include/ArrayOperations.h
        src/ArrayOperations.cpp
        include/Menu.h
        src/Menu.cpp
)
