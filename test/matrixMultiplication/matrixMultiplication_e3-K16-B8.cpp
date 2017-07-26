#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("47561",8,"1653806537",{"280696826","465535919","2158822494","2093431220","1755942458","2111563125","7635817","2125961952","204410927"},"1653114814","1386011792", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("1013735417",cs);
	a[0][1] = SecureInt("1067573247",cs);
	a[0][2] = SecureInt("1177645277",cs);
	a[1][0] = SecureInt("412452430",cs);
	a[1][1] = SecureInt("823355206",cs);
	a[1][2] = SecureInt("1068178663",cs);
	a[2][0] = SecureInt("1552809109",cs);
	a[2][1] = SecureInt("1909186760",cs);
	a[2][2] = SecureInt("1368312420",cs);

	b[0][0] = SecureInt("248420227",cs);
	b[0][1] = SecureInt("242371230",cs);
	b[0][2] = SecureInt("108982526",cs);
	b[1][0] = SecureInt("1959426454",cs);
	b[1][1] = SecureInt("2010331190",cs);
	b[1][2] = SecureInt("951293765",cs);
	b[2][0] = SecureInt("1330402101",cs);
	b[2][1] = SecureInt("1475096847",cs);
	b[2][2] = SecureInt("1789392964",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("1257351135",cs);
			for (int k = 0; k < 3; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << c[i][j].str() << " ";
		cout << "\n";
	}

	return 0;
}

