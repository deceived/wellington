cmake_minimum_required(VERSION 2.8)

project(liblog_project)

add_library(log STATIC logger.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

install(TARGETS log DESTINATION lib)
