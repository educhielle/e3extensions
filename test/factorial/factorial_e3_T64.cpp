#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("12923003053825267069","16","118895003575693580874208211003618856827","51180577483139232161694318239590126104","136539816436322443674065174196854633810", libgDir, gFunctionName);

	SecureInt num("105511823580458364655259250124388465779",cs);
	SecureInt fact("98979532295097417368627881785960296207",cs);
	SecureInt i("43010960129649173740454150684376537047",cs);
	SecureInt result("16038179290955374804167630730647170558",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

