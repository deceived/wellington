cmake_minimum_required(VERSION 2.8)

project(libxml_project)

add_library(xml STATIC pugixml.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

install(TARGETS xml DESTINATION lib)
