cmake_minimum_required(VERSION 3.10)
project(SortProgram)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sorting src/main.c src/sort.c)

target_compile_options(sorting PRIVATE -Wall -Wextra)

enable_testing()
add_test(NAME SortingTest COMMAND sorting)
