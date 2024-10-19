cmake_minimum_required(VERSION 3.29)
project(sistema_cadastro C)

set(CMAKE_C_STANDARD 11)

add_executable(sistema_cadastro main.c
        functions.c
        functions.h
        struct.c
        struct.h)
