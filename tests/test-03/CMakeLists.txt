cmake_minimum_required(VERSION 3.28)
project(test_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_3
        Tool.cpp
        Tool.h
        hardwareStore.cpp)
