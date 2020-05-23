cmake_minimum_required(VERSION 3.13)
project(LPS6)

set(CMAKE_CXX_STANDARD 14)

add_executable(LPS6 main.cpp global.h parser.cpp sortFunc.cpp fileFunc.cpp crudFunc.cpp computedFunc.cpp)