cmake_minimum_required(VERSION 3.4)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES l1/e1.cpp)
add_executable(e1.1 ${SOURCE_FILES})

set(SOURCE_FILES l1/e2.cpp)
add_executable(e1.2 ${SOURCE_FILES})

set(SOURCE_FILES l1/e3.cpp)
add_executable(e1.3 ${SOURCE_FILES})

set(SOURCE_FILES l1/e4.cpp)
add_executable(e1.4 ${SOURCE_FILES})

set(SOURCE_FILES l2/e1.cpp)
add_executable(e2.1 ${SOURCE_FILES})

set(SOURCE_FILES l2/e2.cpp)
add_executable(e2.2 ${SOURCE_FILES})

set(SOURCE_FILES l2/e3.cpp)
add_executable(e2.3 ${SOURCE_FILES})
