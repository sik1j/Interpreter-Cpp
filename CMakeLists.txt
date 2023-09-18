cmake_minimum_required(VERSION 3.26)
project(Interpreter_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Interpreter_Cpp
        Lox.cpp
        Lox.h
        main.cpp
        Token.h
        Token.cpp
        Scanner.cpp
        Scanner.h
)
