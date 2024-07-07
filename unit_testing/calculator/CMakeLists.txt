
cmake_minimum_required(VERSION 3.10)

project(Calculator)

set(CMAKE_CXX_STANDARD 14)


set(GOOGLETEST_DIR ../gtest/googletest)

add_subdirectory(${GOOGLETEST_DIR} ${CMAKE_BINARY_DIR}/googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${GOOGLETEST_DIR}/googletest/include)
include_directories(${GOOGLETEST_DIR}/googlemock/include)



#add_executable(calc src/Calculator.cpp)

add_executable(calc src/Calculator_test.cpp src/Calculator.cpp)
target_link_libraries(calc gtest gtest_main)