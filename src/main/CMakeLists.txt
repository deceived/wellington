cmake_minimum_required(VERSION 2.8)

project(welly)

add_subdirectory(libxml_project)
add_subdirectory(libui_project)
add_subdirectory(libactors_project)
add_subdirectory(libevents_project)
add_subdirectory(liblog_project)

add_executable(welly main.cpp)
target_link_libraries(welly lib)

install(TARGETS welly DESTINATION game)
