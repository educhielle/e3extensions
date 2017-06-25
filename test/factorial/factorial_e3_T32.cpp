#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2926213153","16","7512064915491435837","5156462397985147976","8151128119383752106", libgDir, gFunctionName);

	SecureInt num("1478876285681231604",cs);
	SecureInt fact("6491697152838554369",cs);
	SecureInt i("631110010556518395",cs);
	SecureInt result("3226455040134342893",cs);
	
	int counter = 1;

	do {
		//cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

