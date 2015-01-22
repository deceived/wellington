#!/usr/bin/make
#

SHELL = /bin/sh

CC = gcc

CFLAGS = -g

LDFLAGS	= -g


OUT = cmd.a

all: $(OUT) 

lex.yy.c : command.l
	flex $<	

command.tab.c : command.y
	bison -v -t -d $<

OBJ = command.tab.o lex.yy.o

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	cp $@ ../../lib

clean:
	@rm -f *.o *.a *.output *.c *.tab.h
	@rm -f ../../lib/$(OUT)

