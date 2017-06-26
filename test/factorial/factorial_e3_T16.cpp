#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("34277","10","901099632","91210021","701410754", libgDir, gFunctionName);

	SecureInt num("410494091",cs);
	SecureInt fact("122321664",cs);
	SecureInt i("1103050539",cs);
	SecureInt result("899691284",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

