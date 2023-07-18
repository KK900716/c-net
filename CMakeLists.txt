cmake_minimum_required(VERSION 3.24)
project(learn_net C)

set(CMAKE_C_STANDARD 11)

link_libraries(ws2_32 wsock32)

add_library(learn_net main.c)

add_executable(main main.c)