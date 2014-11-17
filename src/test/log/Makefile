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

LIBS    = -l:libboost_log.a -l:libboost_thread.a -l:libboost_system.a -lpthread
LDFLAGS	= $(LIBDIRS)

prefix = ../../../test

SRCS = test_log.cpp 
OBJS = $(SRCS:.cpp=.o)
OUT  = test_log

all: $(OUT) 

$(OUT): $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: all
	cp $(OUT) $(prefix)

clean:
	@rm -f *.o $(OUT) 

uninstall:
	@rm -f $(prefix)/$(OUT)

