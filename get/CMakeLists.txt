cmake_minimum_required(VERSION 3.20)
project(get)

set(CMAKE_C_STANDARD 23)

add_executable(
        get
        main.c
        get_file.c
)