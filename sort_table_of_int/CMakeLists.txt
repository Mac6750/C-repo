cmake_minimum_required(VERSION 3.24)
project(sort_table_of_int C)

set(CMAKE_C_STANDARD 11)

add_executable(sort_table_of_int main.c)

target_link_libraries(sort_table_of_int m)