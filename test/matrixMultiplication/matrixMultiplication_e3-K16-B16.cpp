#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("50429",14,"1120602376",{"2126252718","2250518202","749187979","350813605","301010190","1177504067","700028097","2010699696","1241358954","226326116","1695046743","1408733467","1213570797","919610755","202043224"},"2055814815","405369603", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("527801918",cs);
	a[0][1] = SecureInt("1990534617",cs);
	a[0][2] = SecureInt("2209339249",cs);
	a[1][0] = SecureInt("1514320523",cs);
	a[1][1] = SecureInt("975274679",cs);
	a[1][2] = SecureInt("874526459",cs);
	a[2][0] = SecureInt("374100993",cs);
	a[2][1] = SecureInt("1738948386",cs);
	a[2][2] = SecureInt("2057465124",cs);

	b[0][0] = SecureInt("591899657",cs);
	b[0][1] = SecureInt("1953985153",cs);
	b[0][2] = SecureInt("1095528422",cs);
	b[1][0] = SecureInt("525036233",cs);
	b[1][1] = SecureInt("2263693179",cs);
	b[1][2] = SecureInt("1473140200",cs);
	b[2][0] = SecureInt("2002045272",cs);
	b[2][1] = SecureInt("631221457",cs);
	b[2][2] = SecureInt("1172884331",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("656036668",cs);
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

