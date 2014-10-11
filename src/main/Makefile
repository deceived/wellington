#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = 
CXXDEBUG = -g 
CXXFLAGS = -Wall -std=c++11

CFLAGS = 	$(CXXDEBUG) \
			$(INCDIRS) \
			$(DEFS) \
			$(CXXFLAGS)

LIBS    = -lncurses -l:libboost_program_options.a
LDFLAGS	=

prefix = ../../game
tmpprefix = ../../tmp

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: welly

welly: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

install: all
	mv welly $(prefix)

clean:
	rm *.o welly

