cmake_minimum_required(VERSION 3.10)
project(SortList)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Sort_list sort_list.c list.c)

target_compile_options(Sort_list PRIVATE -Wall -Wextra)

enable_testing()
add_test(NAME SortListTest COMMAND Sort_list --test)
