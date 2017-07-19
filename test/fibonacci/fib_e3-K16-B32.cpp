#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("34277",10,"29447329",{"354875800","62510525","599411663","144421554","598366886","392873576","519007863","174355988","246998956","307016740","283272889"},"507222237","287220360", libgDir, gFunctionName);

	SecureInt num("756288505",cs);
	SecureInt f1("1038452351",cs);
	SecureInt f2("113882260",cs);
	SecureInt fi("739115517",cs);
	SecureInt i("941339631",cs);
	SecureInt result("875531172",cs);

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

