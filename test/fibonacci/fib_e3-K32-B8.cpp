#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("1947539681",8,"2385804614270151588",{"64265206163304137","3022924343593763642","2775455596800707341","637199277723576901","2340040484341108264","1310342007446171987","1170984512444136754","1709242269026955774","221818836692284733"},"2261725872051577585","2277078428796612848", libgDir, gFunctionName);

	SecureInt num("487119960857047999",cs);
	SecureInt f1("2237461846110904209",cs);
	SecureInt f2("2299721573953859201",cs);
	SecureInt fi("357646679945644447",cs);
	SecureInt i("2920166196325343812",cs);
	SecureInt result("2282041855791540521",cs);

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

