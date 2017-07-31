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
		Cryptosystem cs("27221",8,{"17551986","167757069","581152818","183309822","62714363","728173945","440855649","472952786","43007925"}, libgDir, gFunctionName);
/*
		SecureInt a, b;
		a = SecureInt(__E(7),cs);
		b = SecureInt(__E(12),cs);
*/
	}

	return 0;
}

