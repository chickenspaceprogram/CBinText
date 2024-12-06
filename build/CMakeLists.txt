cmake_minimum_required(VERSION 3.15)
project(cbintxt C)

set(CMAKE_C_STANDARD 11)
add_executable(cbintxt
        ../src/main.c
        ../src/argparse.h
        ../src/argparse.c
        ../src/tokenize.h
        ../src/tokenize.c
        ../src/file-handling.c
        ../src/file-handling.h
	../src/help.h
	../src/help.c
)
