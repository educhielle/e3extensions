#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("9038022972022798609","8","39401116185471622085007085681713387526","14000286787954765545466198534455283448","49648808577137266707828696857318372361", libgDir, gFunctionName);

	SecureInt num("58367180241681438315727989682188823748",cs);
	SecureInt fact("16357652902977382744022797622022613143",cs);
	SecureInt i("78462372866183886952976728117546972542",cs);
	SecureInt result("37652449089567948027852313663103997416",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

