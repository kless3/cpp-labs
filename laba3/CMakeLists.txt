cmake_minimum_required(VERSION 3.28)
project(laba3)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba3 src/main.cpp
        include/Shape.h
        include/Circle.h
        src/Circle.cpp
        include/Square.h
        src/Square.cpp
        src/Triangle.cpp
        include/Menu.h
        src/Menu.cpp)
