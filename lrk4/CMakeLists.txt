cmake_minimum_required(VERSION 3.28)
project(lrk4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lrk4 src/main.cpp
        src/YoungMan.cpp
        src/Person.cpp
        src/Girl.cpp
        include/Girl.h
        include/Person.h
        include/YoungMan.h)
