#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2378347861","16","4119107803365329192","985074750060043879","1202647101586592744", libgDir, gFunctionName);

	SecureInt num("3424734801576502952",cs);
	SecureInt fact("3801015128902829814",cs);
	SecureInt i("4250830266978644793",cs);
	SecureInt result("822214526885585268",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

