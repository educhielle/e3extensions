#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("31553",13,"274039413",{"904550936","681029848","671053236","310739955","693019342","464770614","282998452","451959410","982254248","898441983","190762094","374962908","605514179","648362342"},"350446783","65722614", libgDir, gFunctionName);

	SecureInt num("474997105",cs);
	SecureInt fact("746851260",cs);
	SecureInt i("642285328",cs);
	SecureInt result("170769039",cs);
	
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

