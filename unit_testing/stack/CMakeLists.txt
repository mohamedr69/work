cmake_minimum_required(VERSION 3.10)

project(Stack)

set(CMAKE_CXX_STANDARD 14)


set(GOOGLETEST_DIR ../gtest/googletest)

add_subdirectory(${GOOGLETEST_DIR} ${CMAKE_BINARY_DIR}/googletest)

include_directories(${GOOGLETEST_DIR}/googletest/include)
include_directories(${GOOGLETEST_DIR}/googlemock/include)
include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(stack src/Stack_test.cpp src/Stack.cpp)

target_link_libraries(stack gtest gtest_main)


