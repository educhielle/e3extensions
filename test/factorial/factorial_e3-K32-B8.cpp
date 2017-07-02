#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("1890819377","8","2873992628668570901","1688538122428387221","561144806205883462", libgDir, gFunctionName);

	SecureInt num("1562459360212102634",cs);
	SecureInt fact("2090972392163853466",cs);
	SecureInt i("1294938165224140957",cs);
	SecureInt result("302002898986027340",cs);
	
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

