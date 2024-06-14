cmake_minimum_required(VERSION 3.28)
project(accounts_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(accounts_class main.cpp
        Account.cpp
        Account.h)
