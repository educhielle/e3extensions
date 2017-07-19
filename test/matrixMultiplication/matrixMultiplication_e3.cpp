#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs(__PQ()()()(), __BETA, __2TOBETA, __HALFTABLE, __ENC0, __ENC1, libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt(__E(1),cs);
	a[0][1] = SecureInt(__E(2),cs);
	a[0][2] = SecureInt(__E(3),cs);
	a[1][0] = SecureInt(__E(2),cs);
	a[1][1] = SecureInt(__E(3),cs);
	a[1][2] = SecureInt(__E(4),cs);
	a[2][0] = SecureInt(__E(3),cs);
	a[2][1] = SecureInt(__E(4),cs);
	a[2][2] = SecureInt(__E(5),cs);

	b[0][0] = SecureInt(__E(1),cs);
	b[0][1] = SecureInt(__E(2),cs);
	b[0][2] = SecureInt(__E(3),cs);
	b[1][0] = SecureInt(__E(2),cs);
	b[1][1] = SecureInt(__E(3),cs);
	b[1][2] = SecureInt(__E(4),cs);
	b[2][0] = SecureInt(__E(3),cs);
	b[2][1] = SecureInt(__E(4),cs);
	b[2][2] = SecureInt(__E(5),cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt(__E(0),cs);
			for (int k = 0; k < 3; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << c[i][j].str() << " ";
		cout << "\n";
	}

	return 0;
}

