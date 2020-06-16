cmake_minimum_required(VERSION 3.16)
project(task C)

set(CMAKE_C_STANDARD 99)

add_executable(task src/main.c src/commands.c src/commands.h)