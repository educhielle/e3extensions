#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("66289","9","3499724430","1152460422","2060355280", libgDir, gFunctionName);

	SecureInt num("2201398082",cs);
	SecureInt fact("3074190800",cs);
	SecureInt i("1358140175",cs);
	SecureInt result("2146638574",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

