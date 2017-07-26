#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("45173",13,"256415819",{"1867405695","1903695486","462588845","1368303627","904152336","1536175431","684827442","1291856108","1106846791","507046598","1584385412","1775507487","1542269952","595568817"},"1071335122","1435198503", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("1525460409",cs);
	a[0][1] = SecureInt("1516342063",cs);
	a[0][2] = SecureInt("630409451",cs);
	a[1][0] = SecureInt("640457112",cs);
	a[1][1] = SecureInt("805330802",cs);
	a[1][2] = SecureInt("1054890374",cs);
	a[2][0] = SecureInt("1641486885",cs);
	a[2][1] = SecureInt("788475476",cs);
	a[2][2] = SecureInt("952064342",cs);

	b[0][0] = SecureInt("255958539",cs);
	b[0][1] = SecureInt("1791695961",cs);
	b[0][2] = SecureInt("1172931433",cs);
	b[1][0] = SecureInt("657080754",cs);
	b[1][1] = SecureInt("290372905",cs);
	b[1][2] = SecureInt("1024355700",cs);
	b[2][0] = SecureInt("232604641",cs);
	b[2][1] = SecureInt("1504777074",cs);
	b[2][2] = SecureInt("1767116877",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("209766498",cs);
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

