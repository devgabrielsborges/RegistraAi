cmake_minimum_required(VERSION 3.29)
project(RegistraAI C)

set(CMAKE_C_STANDARD 11)

add_executable(RegistraAI main.c
        functions.c
        functions.h
        struct.c
        struct.h)
