cmake_minimum_required(VERSION 3.28)
project(lrk7)

set(CMAKE_CXX_STANDARD 23)

add_executable(lrk7 src/main.cpp
        include/ObjectFile.h
        src/ObjectFile.cpp
        src/Menu.cpp
        include/Object.h
        include/Cat.h
        src/Cat.cpp
        include/Car.h
        src/Car.cpp
        include/Rose.h
        src/Rose.cpp)
