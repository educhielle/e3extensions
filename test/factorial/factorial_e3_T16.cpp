#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("49949","13","651688211","713828971","1586233819", libgDir, gFunctionName);

	SecureInt num("2084318123",cs);
	SecureInt fact("78866751",cs);
	SecureInt i("504306836",cs);
	SecureInt result("608053317",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

