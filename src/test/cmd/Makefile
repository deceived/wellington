#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

INCDIRS = -I../cmd
LIBDIRS = -L../../lib

CXXFLAGS = $(INCDIRS) -g -Wall -std=c++11

LDFLAGS	= -g $(LIBDIRS) 

LIB = -l:cmd.a -lfl

SRC = bmain.cpp

OBJ = (SRC:.cpp=.o)

all: test_cmd 

test_cmd: $(OBJ)
	$(CXX) $(INCLUDES) -o $@ $(CXXFLAGS) $(OBJ) $(LIB) 

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a 
	@rm -f ../../lib/$(OUT)

