cmake_minimum_required(VERSION 3.11)

project(test)

include_directories(.)

add_executable(${PROJECT_NAME} test.cpp myprint.cpp)
