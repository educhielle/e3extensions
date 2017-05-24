AR=ar
CC=gcc
CXX=g++

ifdef COMPILER
AR := $(COMPILER)$(AR)
CC := $(COMPILER)$(CC)
CXX := $(COMPILER)$(CXX)
endif

ifdef STATIC_LIBG
OPT := -DSTATIC_LIBG=$(STATIC_LIBG) $(OPT)
else
LDFLAGS := -ldl
endif

ifeq ($(STATIC_LIBGCC),1)
LDF := -static-libgcc $(LDF)
endif

ifeq ($(STATIC_LIBSTDCPP),1)
LDF := -static-libstdc++ $(LDF)
endif

ifeq ($(GMP),1)
OPT := -DGMP=1 $(OPT)
LDF := -lgmpxx -lgmp $(LDF)
endif

ifeq ($(STATIC),1)
OPT := -static $(OPT)
endif

ifeq ($(GMP_ASSEMBLY),0)
GMP_PARAMS := --disable-assembly $(GMP_PARAMS)
endif

ifeq ($(GMP_SHARED),0)
GMP_PARAMS := --disable-shared $(GMP_PARAMS)
endif

ifeq ($(ARCH),64)
OPT := -DARCH64 $(OPT)
endif

ARFLAGS=-cvq
CFLAGS=-Wall -O2 -fPIC
CXXFLAGS=-Wall -O2 -std=c++14 -fPIC -fno-strict-aliasing

BIN=bin
LIB=lib
OBJ=obj
SRC=src
TMP=tmp

SRC_E3EXTENSIONS=$(SRC)/e3extensions
OBJ_E3EXTENSIONS=$(OBJ)/e3extensions

SRC_LIBG=$(SRC)/libg
OBJ_LIBG=$(OBJ)/libg

SRC_PREPROCESSOR=$(SRC)/preprocessor
OBJ_PREPROCESSOR=$(OBJ)/preprocessor

OBJ_UNUMBER=$(OBJ)/unumber
SRC_UNUMBER=$(SRC)/unumber

LOCAL_DIR=$(abspath .)
FILE_DIR=$(dir $(IN))
FILENAME=$(notdir $(IN))
LD_LIBRARY_PATH=./lib

INSTALL_GMP_DIR=$(LOCAL_DIR)/build-gmp
HOST=or1k-linux-musl

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-22s\033[0m %s\n", $$1, $$2}'

clean:
	rm -f $(BIN)/*
	rm -f $(LIB)/*
	rm -f $(OBJ_UNUMBER)/*

compile: ## Compile code. Usage: make compile IN=path/to/code OUT=path/to/output [GMP=1] [STATIC=1]
	$(CXX) $(CXXFLAGS) $(IN) $(OBJ_E3EXTENSIONS)/cryptosystem.o $(OBJ_E3EXTENSIONS)/secureint.o $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(OUT) $(OPT) $(LDF) $(LDFLAGS)

compile-decrypt: ## Compile Decrypt. Usage: make compile-decrypt [GMP=1]
	$(CXX) -c $(CXXFLAGS) $(SRC_PREPROCESSOR)/decrypt.cpp -o $(OBJ_PREPROCESSOR)/decrypt.o
	$(CXX) $(CXXFLAGS) $(OBJ_PREPROCESSOR)/decrypt.o $(OBJ_PREPROCESSOR)/big_random.o $(OBJ_PREPROCESSOR)/sensitive_information.o $(OBJ_PREPROCESSOR)/util.o $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(BIN)/decrypt $(OPT) $(LDF)

compile-decrypt-all: compile-unumber compile-sensitive-information compile-decrypt ## Recompile all dependencies and compile Decrypt. Usage: make compile-decrypt-all [GMP=1] [ARCH=64]

compile-e3extensions: ## Compile e3extensions. Usage: make compile-e3extensions [STATIC_LIBG=path/to/libg] [ARCH=64]
	$(CXX) -c $(CXXFLAGS) $(SRC_E3EXTENSIONS)/cryptosystem.cpp -o $(OBJ_E3EXTENSIONS)/cryptosystem.o $(OPT) $(LDF)
	$(CXX) -c $(CXXFLAGS) $(SRC_E3EXTENSIONS)/secureint.cpp -o $(OBJ_E3EXTENSIONS)/secureint.o $(OPT) $(LDF)

compile-preprocessor: ## Compile Preprocessor. Usage: make compile-preprocessor [GMP=1]
	$(CXX) -c $(CXXFLAGS) $(SRC_PREPROCESSOR)/preprocessor.cpp -o $(OBJ_PREPROCESSOR)/preprocessor.o
	$(CXX) $(CXXFLAGS) $(OBJ_PREPROCESSOR)/preprocessor.o $(OBJ_PREPROCESSOR)/big_random.o $(OBJ_PREPROCESSOR)/sensitive_information.o $(OBJ_PREPROCESSOR)/util.o $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(BIN)/preprocessor $(OPT) $(LDF)

compile-preprocessor-all: compile-unumber compile-sensitive-information compile-preprocessor ## Recompile all dependencies and compile Preprocessor. Usage: make compile-preprocessor [GMP=1] [ARCH=64]

compile-shared-libg:
	$(CXX) $(CXXFLAGS) -c $(SRC_LIBG)/libg.cpp -o $(OBJ_LIBG)/libg.o $(OPT) $(LDF)
	$(CXX) $(CXXFLAGS) -shared $(OBJ_LIBG)/libg.o $(OBJ_UNUMBER)/unumberg.o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OBJ_UNUMBER)/ma_invert_m.o -o $(LIB)/libg.so $(OPT) $(LDF)

compile-sensitive-information: ## Compile Sensitive Information class and auxiliary libraries. Usage: make compile-sensitive-information [ARCH=64]
	$(CXX) -c $(CXXFLAGS) $(SRC_PREPROCESSOR)/big_random.cpp -o $(OBJ_PREPROCESSOR)/big_random.o $(OPT) $(LDF)
	$(CXX) -c $(CXXFLAGS) $(SRC_PREPROCESSOR)/sensitive_information.cpp -o $(OBJ_PREPROCESSOR)/sensitive_information.o $(OPT) $(LDF)
	$(CXX) -c $(CXXFLAGS) $(SRC_PREPROCESSOR)/util.cpp -o $(OBJ_PREPROCESSOR)/util.o $(OPT) $(LDF)

compile-static-libg:
	$(CXX) -c $(CXXFLAGS) $(SRC_LIBG)/libg.cpp -o $(OBJ_LIBG)/libg.o $(OPT) $(LDF) -DSTATIC_LIBG
	$(AR) $(ARFLAGS) $(LIB)/libg.a $(OBJ_LIBG)/libg.o

compile-unumber: ## Compile Unumber library. Usage: make compile-unumber [GMP=1]
	$(CXX) -c $(CXXFLAGS) $(SRC_UNUMBER)/unumberg.cpp -o $(OBJ_UNUMBER)/unumberg.o  $(OPT) $(LDF)
	$(CC) -c $(CFLAGS) $(SRC_UNUMBER)/cunmber_4096_m.c -o $(OBJ_UNUMBER)/cunmber_4096_m.o $(OPT) $(LDF)
	$(CXX) -c $(CXXFLAGS) $(SRC_UNUMBER)/ma_invert_m.cpp -o $(OBJ_UNUMBER)/ma_invert_m.o $(OPT) $(LDF)

cross-compile-gmp:
	[ -s "gmp-6.1.2.tar.xz" ] || wget https://gmplib.org/download/gmp/gmp-6.1.2.tar.xz
	[ -s "gmp-6.1.2" ] || tar xf gmp-6.1.2.tar.xz
	test -s $(INSTALL_GMP_DIR) || mkdir $(INSTALL_GMP_DIR)
	cd gmp-6.1.2 ; ./configure --host=$(HOST) --enable-cxx --prefix=$(INSTALL_GMP_DIR) $(GMP_PARAMS) ; make ; make install


decrypt: ## Decrypt file. Usage: make decrypt IN=path/to/inputfile OUT=path/to/outputfile CS=path/to/cryptosystem
	$(BIN)/decrypt $(IN) $(OUT) $(CS)

install: clean compile-unumber compile-preprocessor compile-shared-libg ## Install all basic components

preprocess: ## Preprocess code. Usage: make preprocessor IN=path/to/code OUT=path/to/output
	$(BIN)/preprocessor $(IN) $(OUT)

run: ## Run program. Usage: make run IN=path/to/file
	cp -f $(LIB)/libg.so $(FILE_DIR)
	cd $(FILE_DIR); ./$(FILENAME)


