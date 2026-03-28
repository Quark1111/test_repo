cmake_minimum_required(VERSION 3.25)
project(Sorting C)

enable_language(ASM)
add_library(Sort OBJECT sort.s)
target_include_directories(Sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(sort_program main.c $<TARGET_OBJECTS:Sort>)
target_link_libraries(sort_program PRIVATE Sort)
