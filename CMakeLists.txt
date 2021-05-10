cmake_minimum_required(VERSION 3.19)
project(MyPeople)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MyPeople
        main.cpp
        mypeople.cpp
        mypeople.h
        mypeople.ui)

