#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define IT 1000

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	for (int i = 0; i < IT; i++)
	{
		Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
/*
		SecureInt a, b;
		a = SecureInt(__E(7),cs);
		b = SecureInt(__E(12),cs);
*/
	}

	return 0;
}

