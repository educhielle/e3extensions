#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("33221",8,"981734317",{"203927763","489428678","913897938","904762085","922273258","219629361","389790507","627048850","416853675"},"31265380","195201459", libgDir, gFunctionName);

	SecureInt num("520733391",cs);
	SecureInt f1("88571303",cs);
	SecureInt f2("489069373",cs);
	SecureInt fi("652249316",cs);
	SecureInt i("1062051348",cs);
	SecureInt result("401914908",cs);

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

