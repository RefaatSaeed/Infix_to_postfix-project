cmake_minimum_required(VERSION 3.25)
project(infix2postfix_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(infix2postfix_project main.cpp stack.cpp header.h infix_to_postfix.cpp intstack.cpp)
