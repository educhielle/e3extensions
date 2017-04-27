#!/bin/bash

build_src=build_src

compile:
	if [ ! -d "$(build_src)" ]; then
		mkdir $(build_src)
	fi
	gcc -c cryptosystem.h $(build_src)/cryptosystem.o

clean:
	rm -rf build_src
