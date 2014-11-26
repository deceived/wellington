cmake_minimum_required(VERSION 2.8)

project(libui_project)

add_library(ui STATIC cmd_model.cpp cmd_view.cpp key_model.cpp key_view.cpp map_model.cpp map_view.cpp stdscr_map_controller.cpp stdscr_view.cpp)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

install(TARGETS ui DESTINATION lib)
