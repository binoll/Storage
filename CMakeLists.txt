cmake_minimum_required(VERSION 3.22)
project(storage C)

set(CMAKE_C_STANDARD 11)

add_executable(
        storage
        main.c
        src/save_file.c
        src/get_file.c
)
