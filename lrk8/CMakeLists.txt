cmake_minimum_required(VERSION 3.28)
project(laba8)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba8 src/main.cpp
        include/Deque.h
        src/Deque.cpp
        include/Menu.h
        src/Menu.cpp
        src/Algorithm.cpp)
