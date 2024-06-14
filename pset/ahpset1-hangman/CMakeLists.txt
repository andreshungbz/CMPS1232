cmake_minimum_required(VERSION 3.27)
project(ahpset1_hangman)

set(CMAKE_CXX_STANDARD 17)

add_executable(ahpset1_hangman main.cpp
        Player.cpp
        Player.h
        Hangman.cpp
        Hangman.h)
