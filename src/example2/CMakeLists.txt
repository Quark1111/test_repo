cmake_minimum_required(VERSION 3.25)
project(paren C)

add_library(stack stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(brackets_checker brackets_checker.c)
target_link_libraries(brackets_checker PRIVATE stack)
