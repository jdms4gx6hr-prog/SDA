cmake_minimum_required(VERSION 4.0)
project(sda C)

set(CMAKE_C_STANDARD 11)
add_executable(main main.c data.c)
add_executable(master master.c)


