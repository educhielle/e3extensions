#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("2384826937","8","2061214969615387396","4499958728448017020","1416884809261877505", libgDir, gFunctionName);

	SecureInt num("4023909639314263587",cs);
	SecureInt f1("772830953642824060",cs);
	SecureInt f2("1434334382902763024",cs);
	SecureInt fi("5291383208616069775",cs);
	SecureInt i("5525370405309575428",cs);
	SecureInt result("2572758952974634055",cs);

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

