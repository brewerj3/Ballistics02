cmake_minimum_required(VERSION 3.22)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ballistics02
        main.c
        newtonCalculation.c newtonCalculation.h)
