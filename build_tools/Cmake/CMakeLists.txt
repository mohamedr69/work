cmake_minimum_required(VERSION 3.9.1)

project(HelloCmake)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_C}/bin)

set(LIBRARY_OUTPUT_PATH &{}/lib)

add_executable(main main.cpp)
