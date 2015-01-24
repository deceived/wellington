#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g


OUT = cmd.a

all: $(OUT) 

scanner.cpp : scanner.l
	flex -+ $<	

parser.tab.cpp : parser.ypp
	bison -v -t -d $<

OBJ = parser.tab.o scanner.o

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.out *.o *.a *.output parser.tab.*pp scanner.*pp
	@rm -f ../../lib/$(OUT)

