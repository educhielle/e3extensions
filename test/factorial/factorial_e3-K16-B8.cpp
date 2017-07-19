#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("29177",8,"559046306",{"761304555","851186097","584242643","345336496","690663999","632737465","800262835","465068757","43451402"},"781052636","587441519", libgDir, gFunctionName);

	SecureInt num("788287820",cs);
	SecureInt fact("448715705",cs);
	SecureInt i("697890299",cs);
	SecureInt result("786674554",cs);
	
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

