#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs(__PQ()()()()__, __BETA__, __2TOBETA__, __ENC0__, __ENC1__, libgDir, gFunctionName);

	SecureInt num(__N(5)__,cs);
	SecureInt fact(__N(1)__,cs);
	SecureInt i(__N(1)__,cs);
	SecureInt result(__N(0)__,cs);
	
	int counter = 1;

	do {
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

