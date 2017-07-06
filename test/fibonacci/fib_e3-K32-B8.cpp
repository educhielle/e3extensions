#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("2768525189",8,"2621192866479390982",{"6559380486477480034","3567470310370092925","3358785914903709447","2870831393472395716","3729793729912012457","2210221817762726499","267279690469495267","5390273208499658849","1069897413131347114"},"1432182313061182247","1703537119040559218", libgDir, gFunctionName);

	SecureInt num("1996453249094008076",cs);
	SecureInt f1("2297363459761921253",cs);
	SecureInt f2("270229491692417228",cs);
	SecureInt fi("3998657811340706261",cs);
	SecureInt i("419523421120835560",cs);
	SecureInt result("404413715755376639",cs);

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

