#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("1360252253",8,"940826571703090367",{"1566799070314869689","1198038510089924745","903205687306473014","1656435015035361236","1089142213102609688","378312027720179365","1025825379397104707","622319746421475266","850691363646397013"},"1253828800186325915","885716053913853235", libgDir, gFunctionName);

	SecureInt num("268466531795027988",cs);
	SecureInt f1("633966293628006763",cs);
	SecureInt f2("1612908936368793287",cs);
	SecureInt fi("447005258216321374",cs);
	SecureInt i("698447863246174419",cs);
	SecureInt result("920878685868884288",cs);

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

