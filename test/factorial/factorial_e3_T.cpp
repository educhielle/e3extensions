#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("9827053102165609657","16","83109792174786326846730099240662881996","69116214313612568197911872187009521095","17349562452481656861722839487697473744", libgDir, gFunctionName);

	SecureInt num("87627376917143983309534786929293561002",cs);
	SecureInt fact("21219405947028907762310196218914062231",cs);
	SecureInt i("38463087238691593968977825943982504652",cs);
	SecureInt result("13286029845759501962206231948012915906",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

