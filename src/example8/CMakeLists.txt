cmake_minimum_required(VERSION 3.25)
project(Warrior C)

add_library(cyclic_list cyclic_list.c)
target_include_directories(cyclic_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main main.c)
target_link_libraries(main PRIVATE cyclic_list)
