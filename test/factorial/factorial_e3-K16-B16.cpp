#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("44929",13,"1214051342",{"1795351630","613231967","1885147962","1044727154","1599073152","1321650299","1502986302","685961714","724733513","383059270","1240556612","1338997931","592769397","1624478434"},"770617459","559718205", libgDir, gFunctionName);

	SecureInt num("1528045120",cs);
	SecureInt fact("1609790601",cs);
	SecureInt i("1203391591",cs);
	SecureInt result("1151464600",cs);
	
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

