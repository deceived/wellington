#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = -I../etc -I../xml -I../ui -I../res -I../actors
LIBDIRS  = -L../../lib
CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) $(CXXFLAGS)

LIBS    = -l:ui.a -l:actors.a -l:pugixml.a -lncurses -l:libboost_program_options.a
LDFLAGS	= $(LIBDIRS)

prefix = ../../game
battle = ../../assets/battles/vitoria

SRCS = 	main.cpp 
OBJS = $(SRCS:.cpp=.o)

all: welly

welly: $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: all
	cp welly $(prefix)
	cp $(battle)/* $(prefix)

clean:
	@rm *.o welly

