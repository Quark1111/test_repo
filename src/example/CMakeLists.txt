cmake_minimum_required(VERSION 3.25)
project(Sorting C)

add_library(Sort sort.c)
target_include_directories(Sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(sort_program main.c)
target_link_libraries(sort_program PRIVATE Sort)
