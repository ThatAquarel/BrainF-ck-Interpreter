cmake_minimum_required(VERSION 3.19)
project(BrainF_ck_Interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(BrainF_ck_Interpreter
        src/main.cpp
        src/parser.hpp
        src/parser.cpp
        src/language.hpp
        src/language.cpp)
