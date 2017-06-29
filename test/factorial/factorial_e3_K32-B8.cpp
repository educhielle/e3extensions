#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2110446389","8","658848116877199451","1389748441773479280","4023375714358376945", libgDir, gFunctionName);

	SecureInt num("2770432952961894031",cs);
	SecureInt fact("3659011526606046144",cs);
	SecureInt i("2509543837343235473",cs);
	SecureInt result("968424416093903663",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

