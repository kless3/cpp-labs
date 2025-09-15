cmake_minimum_required(VERSION 3.28)
project(lrk3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lrk3 src/main.cpp
        include/Fakultet.h
        src/Fakultet.cpp
        include/Student.h
        src/Student.cpp)
