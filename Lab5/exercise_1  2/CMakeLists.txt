cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_FLAGS "-std=gnu99")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-03 -DNDEBUG -s")

# Set the project name
project(exercise_1)

# Add includes
include_directories(include)

# Add the executable
add_executable(${CMAKE_PROJECT_NAME} 
    src/main.c
    src/functions.c)

target_link_libraries(${CMAKE_PROJECT_NAME})