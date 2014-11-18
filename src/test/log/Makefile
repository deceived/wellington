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

LIBS    = -l:libboost_log.a -l:libboost_log_setup.a -l:libboost_thread.a -l:libboost_filesystem.a -l:libboost_system.a -lpthread
LDFLAGS	= $(LIBDIRS)

prefix = ../../../test

SRCS1 = test_log.cpp 
SRCS2 = tutorial_log.cpp 

OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

OUT1  = test_log 
OUT2  = tutorial_log

all: $(OUT1) $(OUT2)

$(OUT1): $(OBJS1) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS1) $(LIBS)

$(OUT2): $(OBJS2) 
	$(CXX) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJS2) $(LIBS)

install: all
	cp $(OUT1) $(prefix)
	cp $(OUT2) $(prefix)

clean:
	@rm -f *.o $(OUT1) 
	@rm -f $(OUT2) 
	@rm -f *.log

uninstall:
	@rm -f $(prefix)/$(OUT1)
	@rm -f $(prefix)/$(OUT2)

