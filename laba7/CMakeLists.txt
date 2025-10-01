cmake_minimum_required(VERSION 3.28)
project(laba7)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba7 src/main.cpp
        include/Employee.h
        src/Employee.cpp
        include/Menu.h
        src/Menu.cpp)
