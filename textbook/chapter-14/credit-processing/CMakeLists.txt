cmake_minimum_required(VERSION 3.28)
project(credit_processing)

set(CMAKE_CXX_STANDARD 17)

add_executable(credit_processing
        ClientData.cpp
        ClientData.h
        transaction.cpp)
