cmake_minimum_required(VERSION 3.28)
project(laba2)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba2 src/main.cpp
        src/Matrix.cpp
        include/Matrix.h
        src/Functions.cpp
        include/Functions.h)
