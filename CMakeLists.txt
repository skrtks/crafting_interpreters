cmake_minimum_required(VERSION 3.20)
project(crafting_interpreters C)

set(CMAKE_C_STANDARD 99)

add_executable(crafting_interpreters main.c common.h chunk.c chunk.h memory.h memory.c debug.c debug.h value.h Value.c)
