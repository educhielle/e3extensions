DEFAULT_C_COMPILER=gcc
DEFAULT_CPP_COMPILER=g++

ifdef C_COMPILER
CC := $(C_COMPILER)
else
CC := $(DEFAULT_C_COMPILER)
endif

ifdef CPP_COMPILER
CXX := $(CPP_COMPILER)
else
CXX := $(DEFAULT_CPP_COMPILER)
endif

ifeq ($(STATIC_LIBG),1)
OPT := -D STATIC_LIBG
else
OPT := -ldl
endif

CFLAGS=-Wall -O2 -fPIC # -static-libgcc -static-libstdc++ 
CXXFLAGS=-Wall -O2 -std=c++14 -fPIC -fno-strict-aliasing # -static-libgcc -static-libstdc++ 

BIN=bin
LIB=lib
OBJ=obj
SRC=src
TMP=tmp

SRC_LIBG=$(SRC)/libg

SRC_PREPROCESSOR=$(SRC)/preprocessor

OBJ_UNUMBER=$(OBJ)/unumber
SRC_UNUMBER=$(SRC)/unumber

LOCAL_DIR=$(abspath .)
FILE_DIR=$(dir $(IN))
FILENAME=$(notdir $(IN))
LD_LIBRARY_PATH=./lib

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-22s\033[0m %s\n", $$1, $$2}'

clean:
	rm -f $(BIN)/*
	rm -f $(LIB)/*
	rm -f $(OBJ_UNUMBER)/*

compile: ## Compile code. Usage: make compile IN=path/to/code OUT=path/to/output [STATIC_LIBG]
	$(CXX) $(CXXFLAGS) $(IN) $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(OUT) $(OPT)

compile-decrypt:
	$(CXX) $(CXXFLAGS) $(SRC_PREPROCESSOR)/decrypt.cpp $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(BIN)/decrypt

compile-preprocessor: ## Compile Preprocessor
	$(CXX) $(CXXFLAGS) $(SRC_PREPROCESSOR)/preprocessor.cpp $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(BIN)/preprocessor

compile-shared-libg:
	$(CXX) $(CXXFLAGS) -shared $(SRC_LIBG)/libg.cpp $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(LIB)/libg.so

compile-unumber: ## Compile Unumber library
	$(CXX) -c $(CXXFLAGS) $(SRC_UNUMBER)/unumberg.cpp -o $(OBJ_UNUMBER)/unumberg.o
	$(CC) -c $(CFLAGS) $(SRC_UNUMBER)/cunmber_4096_m.c -o $(OBJ_UNUMBER)/cunmber_4096_m.o
	$(CXX) -c $(CXXFLAGS) $(SRC_UNUMBER)/ma_invert_m.cpp -o $(OBJ_UNUMBER)/ma_invert_m.o

decrypt: ## Decrypt file. Usage: make decrypt IN=path/to/inputfile OUT=path/to/outputfile CS=path/to/cryptosystem
	$(BIN)/decrypt $(IN) $(OUT) $(CS)

install: clean compile-unumber compile-preprocessor compile-shared-libg ## Install all basic components

preprocess: ## Preprocess code. Usage: make preprocessor IN=path/to/code OUT=path/to/output
	$(BIN)/preprocessor $(IN) $(OUT)

run: ## Run program. Usage: make run IN=path/to/file
	cp -f $(LIB)/libg.so $(FILE_DIR)
	cd $(FILE_DIR); ./$(FILENAME)
#	cd $(LOCAL_DIR)
#	rm -f $(FILE_DIR)libg.so

