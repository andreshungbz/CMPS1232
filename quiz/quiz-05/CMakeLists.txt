cmake_minimum_required(VERSION 3.28)
project(o_quiz)

set(CMAKE_CXX_STANDARD 17)

add_executable(o_quiz writeCities.cpp
        City.cpp
        City.h)
