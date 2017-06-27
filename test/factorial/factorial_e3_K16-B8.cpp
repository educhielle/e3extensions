#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("37909","8","333065373","414009683","1271483429", libgDir, gFunctionName);

	SecureInt num("88075793",cs);
	SecureInt fact("140192229",cs);
	SecureInt i("920952364",cs);
	SecureInt result("1151657908",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

