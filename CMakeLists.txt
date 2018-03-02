cmake_minimum_required(VERSION 3.9)
project(CContainers C)

set(CMAKE_C_STANDARD 11)

add_library(List List.c List.h)

add_library(HashSet HashSet.c HashSet.h)

add_executable(Main main.c)

target_link_libraries(Main List HashSet)
