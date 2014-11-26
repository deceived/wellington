cmake_minimum_required(VERSION 2.8)

project(liblog_project)

add_library(log STATIC actor.cpp actor_factory.cpp fire_component.cpp identity_component.cpp move_component.cpp representation_component.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

install(TARGETS log DESTINATION lib)
