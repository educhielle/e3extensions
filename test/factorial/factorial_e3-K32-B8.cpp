#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2601271753","8","4433745283040183053","4774682784615626600","4106496055432668143", libgDir, gFunctionName);

	SecureInt num("6216921865687767616",cs);
	SecureInt fact("4597679484791637768",cs);
	SecureInt i("5449564612344154743",cs);
	SecureInt result("4283362205506280808",cs);
	
	int counter = 1;

	do {
		//cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
		++i;
	} while (++counter != MAX_NUM);

	cout << "fact( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

