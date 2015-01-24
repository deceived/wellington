#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g


OUT = cmd.a

all: $(OUT) 

lex.yy.cc : scanner.l
	flex -+ $<	

y.tab.c : parser.y
	bison++ -v -t -d $<

OBJ = y.tab.o lex.yy.o

.cc.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

.c.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.out *.o *.a *.output *.c *.cc *.tab.h
	@rm -f ../../lib/$(OUT)

