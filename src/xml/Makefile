#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -Wall -std=c++11

CFLAGS = $(CXXFLAGS)

LDFLAGS	= -g

SRC = pugixml.cpp
OBJ = $(SRC:.cpp=.o)
OUT = pugixml.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)

clean:
	@rm *.o *.a

