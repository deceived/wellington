cmake_minimum_required( VERSION 2.6 )
project( wellington )

set( ncurses_VERSION_MAJOR 1 )
set( ncurses_VERSION_MINOR 0 )

configure_file (
  "${PROJECT_SOURCE_DIR}/wellington_config.h.in"
  "${PROJECT_BINARY_BIN}/wellington_config.h"
)

include_directories( "${PROJECT_BINARY_DIR}" )

add_executable( wellington main.cpp )
