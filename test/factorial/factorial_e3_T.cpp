#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("1616438909","16","2126414955237795355","953492254844637334","2503827040014288176", libgDir, gFunctionName);

	SecureInt num("1435497660098623189",cs);
	SecureInt fact("1208537114609574710",cs);
	SecureInt i("1686811866000204252",cs);
	SecureInt result("237270769388420133",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

