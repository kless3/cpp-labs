cmake_minimum_required(VERSION 3.28)
project(lrk1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lrk1
        include/Matrix.h
        src/main.cpp
        src/Matrix.cpp
        src/Functions.cpp
        include/Functions.h

)
