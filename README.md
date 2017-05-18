# e3extensions

TODO: project description

## Contents

* [Install](#install)
* [Usage](#usage)
* [TL;DR](#tldr)
* [Static vs Dynamic LibG](#static-vs-dynamic-libg)
* [Supported Operations](#supported-operations)
* [Cross Compiling](#cross-compiling)

## Install

In the e3extensions base directory:
````
make install
````

## Usage

### Coding

Follow the examples in the *test* directory.

### Preprocessing

If instead of hardcoding the arguments for the Cryptosystem and SecureInt objects, you decide to use the preprocessor capabilitities (as in *test/main/main.cpp*), you must to pass your code through the preprocessor.

In the *e3extensions* directory, do:

````
make preprocess IN=test/main/main.cpp OUT=test/main/main\_T.cpp
````

### Compiling

The code generated by the preprocessor must be the one compiled.

From the *e3extensions* directory:
````
make compile IN=test/main/main_T.cpp OUT=test/main/main.elf
````
If using static libg:
````
make compile IN=test/main/main\_T.cpp OUT=test/main/main.elf STATIC\_LIBG=1
````
If using another compiler:
````
make compile IN=test/main/main\_T.cpp OUT=test/main/main.elf CC=or1k-elf-gcc CXX=or1k-elf-g++
````

### Running

In the *e3extensions* directory, do:
```
make run IN=test/main/main.elf
```

### Decrypting

In the *e3extensions* directory, do as the following example:
````
make decrypt IN=test/simple/output.txt OUT=test/simple/output_dec.txt CS=test/simple/CS.txt
```` 

## TL;DR

Let us create a program that performs a simple mathematical equation (1+15*10-7). First, create a directory in *test/*.
````
cd test/
mkdir simple
cd simple/
````
Create a C++ file (simple.cpp).
````
#include <iostream>
#include <fstream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	cout << "Creating Cryptosystem\n";
	Cryptosystem cs(__PQ()()()()__, __BETA__, __2TOBETA__, __ENC0__, __ENC1__, libgDir, gFunctionName);
	cout << "Instantiating SecureInts\n";
	SecureInt a(__N(1)__,cs), b(__N(15)__,cs), c(__N(10)__,cs), d(__N(7)__,cs);
	cout << "Performing mathematical equation (it may take a while)\n";
	SecureInt r = a+b*c-d;
	cout << "Writing output file\n";
	ofstream out;
	out.open("output.txt", ofstream::out);
	out << r.str();
	out.close();

	return 0;
}

````
Then, from the e3extensions directory, let us use the makefile to preprocess the code:
````
make preprocess IN=test/simple/simple.cpp OUT=test/simple/simple_T.cpp
````
Now, compile the program:
````
make compile IN=test/simple/simple_T.cpp OUT=test/simple/simple.elf
````
Run the application:
````
make run IN=test/simple/simple.elf
````
It creates a file called output.txt with the encrypted result and shows the following messages during the run:
````
Creating Cryptosystem
Instantiating SecureInts
Performing mathematical equation (it may take a while)
Writing output file
````
If you check the output.txt, you will see an encrypted value. To see the unencrypted result:
````
make decrypt IN=test/simple/output.txt OUT=test/simple/output_dec.txt CS=test/simple/CS.txt
````
The decryption of *output.txt* is then available in the file *output_dec.txt*. It shows 144 as the result.

## Static vs Dynamic LibG

The Cryptosystem supports dynamic \(shared object\) or static \(include\) loading of LibG. The use of dynamic libG allows several G functions in the same code. But if the code is targeting baremetal or you are planning to use only one G function, the static libG may be more appropriate. The dynamic approach is the standard. To use the static, you must:
* *#define STATIC_LIBG* in the beggining of your code \(see *test/main/main.cpp*\)\*
* *#include "path/to/your/libg"* before including *secureint.h*
* name your G function in your libg file as *libg* \(see *src/libg/libg.cpp*\)
\*an alternative to defining STATIC_LIBG in the code is compiling the program with the flag STATIC_LIBG=1, ex:
````
make compile IN=test/main/main_T.cpp OUT=test/main/main.elf STATIC_LIBG=1
````

## Supported Operations

To help explaining the operators, SecureInt objects a and b containing encrypted values and k containing an unsigned integer are used.
Note: a ~ before a number means the encryption of that number and a _ before a variable means the decryption of that variable.

* **==** \(usage a==b\) returns ~1 if a is equal to b is true, and ~0 otherwise
* **\!=** \(usage a!=b\) returns ~1 if a is different from b is true, and ~0 otherwise
* **\+** \(unary, usage +a\) returns a
* **\+** \(binary, a+b\) returns an encrypted number that, if decrypted, is equivalent to the sum of _a and _b
* **\+=** \(a\+=b\) same as above, but the returned value is automatically attributed to a
* **\-** \(unary, usage -a\) returns the inverse of a, which, if decrypted, is equivalent to -(_a)
* **\-** \(binary, usage a-b\) returns an encrypted number that, is decrypted, is equivalent to subtracting b from a
* **\-=** \(a-=b\) same as above, but the returned value is automatically attributed to a
* **\*** \(a\*b\) return an encrypted number that (if decrypted) is equivalent to the multiplication of _a and _b
* **\*=** \(a\*=b\) same as above, but the returned value is automatically attributed to a
* **<<** \(a<<k\) returns an encrypted value that, if decrypted, is the same as shifting left _a k times
* **<<=** \(a<<=k\) same as above, but the returned value is automatically attributed to a
* **\>\>** \(a\>\>k\) returns an encrypted value that, if decrypted, is the same as shifting right _a k times
* **\>\>=** \(a\>\>=k\) same as above, but the returned value is automatically attributed to a


## Cross Compiling

To cross compile your code, use one of the following methods. Examples cross compiling to *openRISC 1000 baremetal* using code *test/main/main.cpp*.

#### Method 1

````
make compile-unumber CC=or1k-elf-gcc CXX=or1k-elf-g++
make preprocess IN=test/main/main.cpp *# if code is already preprocessed, this comand is not necessary*
make compile IN=test/main/main_T.cpp OUT=test/main/main.elf STATIC_LIBG=1 CC=or1k-elf-gcc CXX=or1k-elf-g++
````

#### Method 2

````
export C_COMPILER=or1k-elf-gcc
export CPP_COMPILER=or1k-elf-g++
make compile-unumber
make preprocess IN=test/main/main.cpp *# if code is already preprocessed, this comand is not necessary*
make compile IN=test/main/main_T.cpp OUT=test/main/main.elf STATIC_LIBG=1
````

## MoMAlab

[Click here](http://sites.nyuad.nyu.edu/moma/) for more.
