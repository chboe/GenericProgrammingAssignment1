cmake_minimum_required(VERSION 3.17)
project(GenericProgrammingAssignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GenericProgrammingAssignment1
        List.cpp
        List.hpp
        Tree.cpp
        Tree.hpp)
