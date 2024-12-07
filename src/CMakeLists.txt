cmake_minimum_required(VERSION 3.15)
project(cbintxt-src C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(arraylist)
add_subdirectory(messages)

add_executable(cbintxt
        main.c
        argparse.h
        argparse.c
        tokenize.h
        tokenize.c
        file-handling.c
        file-handling.h
)

target_link_libraries(cbintxt messages arraylist)