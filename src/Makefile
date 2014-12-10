#!/usr/bin/make

all: 
	$(MAKE) -C log
	$(MAKE) -C ui
	$(MAKE) -C io 
	$(MAKE) -C xml
	$(MAKE) -C actors
	$(MAKE) -C main

install:
	$(MAKE) -C main install

clean:
	$(MAKE) -C log clean
	$(MAKE) -C ui clean
	$(MAKE) -C io clean
	$(MAKE) -C xml clean
	$(MAKE) -C actors clean
	$(MAKE) -C main clean

uninstall:
	$(MAKE) -C main uninstall
