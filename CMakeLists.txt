cmake_minimum_required(VERSION 3.24)
project(Proyecto_Zoologico)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_Zoologico main.cpp Zoo.cpp Zoo.h Habitat.cpp Habitat.h Animal.cpp Animal.h)
