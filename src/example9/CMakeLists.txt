cmake_minimum_required(VERSION 3.25)
project(Sort_list C)

add_library(list list.c)
target_include_directories(list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main sort_list.c)
target_link_libraries(main PRIVATE list)
