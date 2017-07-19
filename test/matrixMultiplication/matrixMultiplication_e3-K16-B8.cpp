#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2865126799",29,"8083932170541102000",{"625333660071738813","6876364434819379732","6093820305048857729","5721412218067062962","4633395140774909403","4366228828438613855","3808849027313582883","5091772029239822557","7413737064948192527","1333947661969082516","6213629521682193688","89187066193957932","3993245263521930893","3147025239157704582","7996317663608998836","5837839253299905181","5857669470615606174","4534289690676720797","6837133756986537290","2861194893862963298","6880337628263058515","1500994988236825895","76932538391461344","2725842544177344599","6102438823899485448","5451877318844874844","522741458372312730","5650644367309025640","6243718893627024913","5061512537117627425"},"2423709583102328759","7600646398919747097", libgDir, gFunctionName);

	SecureInt a ("4102212958509706723",cs);
	SecureInt b ("2773145962483754313",cs);
	SecureInt c ("2643398395139553921",cs);
	SecureInt d ("6116608565553313513",cs);
	SecureInt e ("2659163136074386453",cs);
	SecureInt f ("4967649231201987645",cs);

	cout << a.str() << b.str() << c.str() << d.str() << e.str() << f.str() << "\n";

/*
	SecureInt a[3][3] = { {SecureInt(1,cs),SecureInt(2,cs),SecureInt(3,cs)}, {SecureInt(2,cs),SecureInt(3,cs),SecureInt(4,cs)}, {SecureInt(3,cs),SecureInt(4,cs),SecureInt(5,cs)} };
	SecureInt b[3][3] = { {SecureInt(1,cs),SecureInt(2,cs),SecureInt(3,cs)}, {SecureInt(2,cs),SecureInt(3,cs),SecureInt(4,cs)}, {SecureInt(3,cs),SecureInt(4,cs),SecureInt(5,cs)} };
	SecureInt c[3][3];
	SecureInt zero (0,cs);
*/
/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = zero;
			for (int k = 0; k < 3; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << c[i][j].str() << " ";
		cout << "\n";
	}
*/

	return 0;
}

