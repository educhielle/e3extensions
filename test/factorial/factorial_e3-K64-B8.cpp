#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("6971072921368002493","8","2169874739419845331878932003536265354","15633932887115887976947788816976064779","2018270048961641697094412314974131198", libgDir, gFunctionName);

	SecureInt num("13342808028409161925984721871142803751",cs);
	SecureInt fact("38458777140100587051582761993951350437",cs);
	SecureInt i("15564131371361685154139743112831612471",cs);
	SecureInt result("43572639113488523782540167646974986451",cs);
	
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

