#!/usr/bin/make

all: 
	$(MAKE) -C ui
	$(MAKE) -C xml
	$(MAKE) -C actors
	$(MAKE) -C main

install:
	$(MAKE) -C main install

clean:
	$(MAKE) -C ui clean
	$(MAKE) -C xml clean
	$(MAKE) -C actors clean
	$(MAKE) -C main clean

uninstall:
	$(MAKE) -C main uninstall
