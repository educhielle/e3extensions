#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("3637817441","8","6701078113711831211","1641765529990760058","1148645148810940889", libgDir, gFunctionName);

	SecureInt num("588208049516986764",cs);
	SecureInt fact("12433206219905632872",cs);
	SecureInt i("7607835539407103445",cs);
	SecureInt result("347730112636449139",cs);
	
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

