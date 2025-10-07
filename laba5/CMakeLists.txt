cmake_minimum_required(VERSION 3.28)
project(laba5)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba5 src/main.cpp
        include/Queue.h
        src/Queue.cpp
        src/Menu.cpp
        include/Menu.h
        include/Node.h)