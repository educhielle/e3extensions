#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2327085181",8,"3215223126777530980",{"3162043221068037380","475034021939272328","5395396925831817321","1415376477857672085","3986551154391179996","2676738621620286584","4339075004375520081","3161968290163539675","5174751960878002476"},"360417544452431899","1991742276969596685", libgDir, gFunctionName);

	SecureInt num("4685802317291715673",cs);
	SecureInt fact("4159354591268979494",cs);
	SecureInt i("4102039960211284424",cs);
	SecureInt result("4815408786086926076",cs);
	
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

