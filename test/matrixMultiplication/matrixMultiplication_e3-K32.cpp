#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("2865126799",29,"291582226628883525",{"611423665111691881","7692354197301381586","3801250112410282324","5377768049999794457","6097764196122215265","5791140272005543994","2964285435104999462","8206491561288690127","6511332598382238496","7706043246976856894","880250664675548707","5641662054863025380","5974882424598084381","7056388282716602947","1906267175605501564","909650021441958405","2009199663191554128","6747873479131282465","2157932406772911877","8200857141871472434","1730340788047651221","475701223905405364","3329526301447989498","2278271428846548035","8021700374893675861","1619535212604732538","1575053683102941462","7071281164592455514","1614497011726992231","6372624847284098283"},"4710804274989012553","202499664483737395", libgDir, gFunctionName);

	SecureInt a ("651059192722124227",cs);
	SecureInt b ("6328150268034100280",cs);
	SecureInt c ("4488147784474278195",cs);
	SecureInt d ("478201642406572665",cs);
	SecureInt e ("1522048360708831380",cs);
	SecureInt f ("783219736159244725",cs);

	cout << a.str() << " " << b.str() << " " << c.str() << " " << d.str() << " " << e.str() << " " << f.str() << "\n";

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

