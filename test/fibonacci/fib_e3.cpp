#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs(__PQ()()()(), __BETA, __2TOBETA, __HALFTABLE, __ENC0, __ENC1, libgDir, gFunctionName);

	SecureInt num(__E(7),cs);
	SecureInt f1(__E(0),cs);
	SecureInt f2(__E(1),cs);
	SecureInt fi(__E(1),cs);
	SecureInt i(__E(1),cs);
	SecureInt result(__E(0),cs);

	int counter = 1;
	do {
		result += (i == num) * fi;
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		++i;
	} while (++counter != MAX_NUM);	
	cout << "fib( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

