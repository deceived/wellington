cmake_minimum_required(VERSION 2.8)

project(libevent_project)

add_library(event STATIC event.cpp event_manager.cpp role_system.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

install(TARGETS events DESTINATION lib)
