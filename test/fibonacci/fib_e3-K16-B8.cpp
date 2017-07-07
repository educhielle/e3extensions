#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("56977",8,"1675233188",{"2311524710","3078926230","2305949533","3240671666","1979708092","298460647","1990097257","1379982416","1510787460"},"1641148093","2863041070", libgDir, gFunctionName);

	SecureInt num("2543689629",cs);
	SecureInt f1("1943230801",cs);
	SecureInt f2("2323453865",cs);
	SecureInt fi("2506079400",cs);
	SecureInt i("1781418072",cs);
	SecureInt result("1961448322",cs);

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

