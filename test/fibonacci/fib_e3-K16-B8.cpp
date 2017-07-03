#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("49949","8","1017452159","1595814936","1194111059", libgDir, gFunctionName);

	SecureInt num("2038176089",cs);
	SecureInt f1("48559983",cs);
	SecureInt f2("264051503",cs);
	SecureInt fi("1712457001",cs);
	SecureInt i("2389984994",cs);
	SecureInt result("1257148974",cs);

	int counter = 1;
	do {
		result += (i == num) * fi;
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		++i;
	} while (++counter != MAX_NUM);	
	cout << "fib( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

