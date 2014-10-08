#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = 
CXXDEBUG =  -g 
CXXFLAGS = 	$(CXXDEBUG) \
			$(INCDIRS) \
			$(DEFS)

LIBS    = -lncurses
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

