#/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g


OUT = cmd.a

SRC = driver.cpp scanner.cpp parser.cpp
OBJ = (SRC:.cpp.o)


all: $(OUT) 

scanner.cpp : scanner.l
	flex -+ $<	

parser.cpp : parser.ypp
	bison -v -t -d -oparser.cpp $<

OBJ = driver.o scanner.o parser.o

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.out *.o *.a *.output parser.tab.*pp 
	@rm -f ../../lib/$(OUT)

