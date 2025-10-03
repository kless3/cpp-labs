cmake_minimum_required(VERSION 3.28)
project(lrk7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lrk7 src/main.cpp
        include/Menu.h
        src/Menu.cpp
        include/FileIndexer.h
        src/FileIndexer.cpp)
