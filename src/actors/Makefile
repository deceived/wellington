#!/usr/bin/make
#

SHELL = /bin/sh

CXX = g++

CXXFLAGS = -g -std=c++11

LDFLAGS	= -g

INCLUDES = -I../etc -I../xml

SRC = 	actor.cpp  actor_component.cpp actor_factory.cpp identity_component.cpp  move_component.cpp
OBJ = $(SRC:.cpp=.o)
OUT = actors.a

all: $(OUT) 

.cpp.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)

clean:
	@rm *.o *.a

