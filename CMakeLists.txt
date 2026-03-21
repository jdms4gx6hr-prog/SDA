cmake_minimum_required(VERSION 4.0)
project(sda C)

set(CMAKE_C_STANDARD 11)

add_executable(sda master.c)

add_executable(lab4 main.c data.c)
