cmake_minimum_required(VERSION 3.25)
project(stan C)

add_library(stack stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Main main.c)
target_link_libraries(Main PRIVATE stack)
