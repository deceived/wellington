#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = 
CXXFLAGS = -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) \
			$(DEFS) \
			$(CXXFLAGS)

LIBS    = -lncurses -l:libboost_program_options.a
LDFLAGS	=

prefix = ../../game
tmpprefix = ../../tmp

SRCS = 	main.cpp \
		cmd_model.cpp \
		cmd_view.cpp \
		key_model.cpp \
		key_view.cpp \
		map_model.cpp \
		map_view.cpp \
		stdscr_map_controller.cpp \
		stdscr_view.cpp 
OBJS = $(SRCS:.cpp=.o)

all: welly

welly: $(OBJS) map.hpp file_reader.hpp
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

install: all
	mv welly $(prefix)

clean:
	@rm *.o welly

