cmake_minimum_required(VERSION 3.9)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_library(LinkedList List.c List.h)

add_executable(Main main.c)

target_link_libraries(Main LinkedList)
