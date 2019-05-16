cmake_minimum_required(VERSION 3.10)
project(dl_list C)

set(CMAKE_C_STANDARD 99)

add_executable(dl_list main.c dl_list.c dl_list.h)