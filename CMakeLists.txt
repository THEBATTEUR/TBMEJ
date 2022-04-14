cmake_minimum_required(VERSION 3.0)
project(RM C)

set(CMAKE_C_STANDARD 99)

add_executable(RM main.c grid/grid.c ia.c ia.h game.c game.h)