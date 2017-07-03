#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("56977","8","1782954572","804887794","3109858915", libgDir, gFunctionName);

	SecureInt num("473940567",cs);
	SecureInt fact("2570836980",cs);
	SecureInt i("1291764718",cs);
	SecureInt result("1678576598",cs);
	
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

