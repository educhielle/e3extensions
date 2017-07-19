#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("1187139281",8,"1028153341503774501",{"823739666362192409","625850239008837831","1079182093139031367","809343204118226913","799615887422394311","1124858015841548905","242498981735017140","1379407050335462941","386201119142338465"},"12098091217492692","867280983365137027", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("316084566290726757",cs);
	a[0][1] = SecureInt("627933366991563091",cs);
	a[0][2] = SecureInt("953357314391518137",cs);
	a[1][0] = SecureInt("1355729584318157878",cs);
	a[1][1] = SecureInt("693983473276768358",cs);
	a[1][2] = SecureInt("307918604239432024",cs);
	a[2][0] = SecureInt("6797455560585796",cs);
	a[2][1] = SecureInt("1036842807780303887",cs);
	a[2][2] = SecureInt("1166630357011225885",cs);

	b[0][0] = SecureInt("592356623615963924",cs);
	b[0][1] = SecureInt("354881837610056480",cs);
	b[0][2] = SecureInt("643819184422355992",cs);
	b[1][0] = SecureInt("769832232390550272",cs);
	b[1][1] = SecureInt("793175166069866198",cs);
	b[1][2] = SecureInt("906418035791848931",cs);
	b[2][0] = SecureInt("931917590665614529",cs);
	b[2][1] = SecureInt("1036896959221073817",cs);
	b[2][2] = SecureInt("702910466039227408",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("655310978394358554",cs);
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

