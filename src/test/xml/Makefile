#!/usr/bin/make
#

SHELL = /bin/sh

srcdir = .

CXX = g++

DEFS = 
INCDIRS  = -I../../etc -I../../xml -I../../ui -I../../res -I../../actors
LIBDIRS  = -L../../../lib
CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

CFLAGS = 	$(INCDIRS) $(CXXFLAGS)

LIBS    = -l:ui.a -l:actors.a -l:pugixml.a -lncurses -l:libboost_program_options.a
LDFLAGS	= $(LIBDIRS)

prefix = ../../../test
battle = ../../../assets/battles/vitoria

SRCS = 	test_pugixml.cpp 
OBJS = $(SRCS:.cpp=.o)
OUT  = test_pugixml

all: $(OUT) 

$(OUT): $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: all
	cp $(OUT) $(prefix)
	cp $(battle)/*.xml $(prefix)

clean:
	@rm -f *.o $(OUT) 

uninstall:
	@rm -f $(prefix)/*.xml
	@rm -f $(prefix)/$(OUT)

