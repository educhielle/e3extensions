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
		Cryptosystem cs("2056433573",8,{"3482199610116663977","3733870410483639522","3036143293384893796","2017818732992210989","900317648814440814","2225450750084932411","1434489375091037316","2293099860825314596","4083866335535621122"}, libgDir, gFunctionName);
/*
		SecureInt a, b;
		a = SecureInt(__E(7),cs);
		b = SecureInt(__E(12),cs);
*/
	}

	return 0;
}

