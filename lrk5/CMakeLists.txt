cmake_minimum_required(VERSION 3.28)
project(lrk5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lrk5 src/main.cpp
        include/Search.h
        include/Menu.h
        src/Menu.cpp
)
