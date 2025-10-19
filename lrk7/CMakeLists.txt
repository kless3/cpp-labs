cmake_minimum_required(VERSION 3.28)
project(lrk7)

set(CMAKE_CXX_STANDARD 23)

add_executable(lrk7 src/main.cpp
        include/FileIndexer.h
        src/FileIndexer.cpp
        src/Menu.cpp)
