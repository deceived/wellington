#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = 
CXXDEBUG = -g 
CXXFLAGS = -Wall
CFLAGS = 	$(CXXDEBUG) \
			$(INCDIRS) \
			$(DEFS) \
			$(CXXFLAGS)

LIBS    = -lncurses
LDFLAGS	= 

prefix = ../../game
tmpprefix = ../../tmp

vpath %.o $(tmpprefix)
 
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: welly

welly: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

install: all
	mv welly $(prefix)

clean:
	rm *.o welly

