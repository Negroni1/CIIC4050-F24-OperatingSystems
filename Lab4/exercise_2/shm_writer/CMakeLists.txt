cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")
set(CMAKE_C_FLAGS "-std=gnu99")

project(shm_writer)
include_directories(include)
add_executable(shm_writer
    src/main.c)
