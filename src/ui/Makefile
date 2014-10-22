#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../etc -I../xml -I../res

SRC = 	cmd_model.cpp cmd_view.cpp \
		key_model.cpp key_view.cpp \
		map_model.cpp map_view.cpp \
		stdscr_map_controller.cpp \
		stdscr_view.cpp
 
OBJ = $(SRC:.cpp=.o)
OUT = ui.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)

clean:
	@rm *.o *.a

