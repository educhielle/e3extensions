#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs(__PQ()()()(), __BETA, __2TOBETA, __HALFTABLE, __ENC0, __ENC1, libgDir, gFunctionName);

	SecureInt num(__E(5),cs);
	SecureInt fact(__E(1),cs);
	SecureInt i(__E(1),cs);
	SecureInt result(__E(0),cs);
	
	int counter = 1;

	do {
		//cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
		++i;
	} while (++counter != MAX_NUM);

	cout << "fact( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

