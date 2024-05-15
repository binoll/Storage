cmake_minimum_required(VERSION 3.20)
project(save)

set(CMAKE_C_STANDARD 23)

add_executable(
        save
        main.c
        save_file.c
)