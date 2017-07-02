#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("1964544733","8","2452921144653521230","2005287370945113984","872984876783875923", libgDir, gFunctionName);

	SecureInt num("1672027984499783162",cs);
	SecureInt f1("2031454095900471500",cs);
	SecureInt f2("766108461817647632",cs);
	SecureInt fi("2988748162329814174",cs);
	SecureInt i("547916034595984433",cs);
	SecureInt result("2990273723928686749",cs);

	int counter = 1;
	do {
		result += (i == num) * fi;
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		++i;
	} while (++counter != MAX_NUM);	
	cout << "fib(" << num.str() << ") = " << result.str() << "\n";

	return 0;
}

