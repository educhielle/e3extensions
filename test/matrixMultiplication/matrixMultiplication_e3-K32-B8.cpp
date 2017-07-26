#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2891798869",8,"4191533549763822619",{"157069928385837037","4720803079812299469","3957903506110679189","2161119570401487058","2298787471752195530","6100098564826787738","2998446755847440590","766865606360985538","3748344614674332557"},"6714017063423407105","5483948343188800588", libgDir, gFunctionName);
	SecureInt a[3][3], b[3][3], c[3][3];

	a[0][0] = SecureInt("2107339529000158470",cs);
	a[0][1] = SecureInt("1677467527589849740",cs);
	a[0][2] = SecureInt("8301699662349659434",cs);
	a[1][0] = SecureInt("1262608251745566027",cs);
	a[1][1] = SecureInt("197223162782306490",cs);
	a[1][2] = SecureInt("5780017387618946035",cs);
	a[2][0] = SecureInt("5773278843259472230",cs);
	a[2][1] = SecureInt("3523693802755888171",cs);
	a[2][2] = SecureInt("5889292650355895942",cs);

	b[0][0] = SecureInt("6739117935825065148",cs);
	b[0][1] = SecureInt("3963936663016544392",cs);
	b[0][2] = SecureInt("7243666246042111990",cs);
	b[1][0] = SecureInt("981138624284307187",cs);
	b[1][1] = SecureInt("1173972743747381310",cs);
	b[1][2] = SecureInt("7564104305711137409",cs);
	b[2][0] = SecureInt("2163927208645786827",cs);
	b[2][1] = SecureInt("378197041897740237",cs);
	b[2][2] = SecureInt("430736205901664903",cs);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = SecureInt("5681655660112719069",cs);
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

