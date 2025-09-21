cmake_minimum_required(VERSION 3.28)
project(laba4)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba4 src/main.cpp
        include/Shape.h
        include/Circle.h
        src/Circle.cpp
        src/Trapezoid.cpp
        src/Rectangle.cpp
        src/RightTriangle.cpp
        include/Menu.h
        src/Menu.cpp)
