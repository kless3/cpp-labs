cmake_minimum_required(VERSION 3.16)
project(tryingQt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/msys64/mingw64/lib/cmake/Qt5")

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(tryingQt main.cpp
        Workout.cpp
        Exercise.cpp
        TrainingDiary.h
        TrainingDiary.cpp
        MainWindow.h
        MainWindow.cpp)

target_link_libraries(tryingQt Qt5::Core Qt5::Widgets)