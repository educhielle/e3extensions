#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("15206451262798095337","8","19816612666861405430262917894869276169","7769608414326252759312974144042396138","200610039401562687790253223466400165778", libgDir, gFunctionName);

	SecureInt num("29839019936657082021816188451341061657",cs);
	SecureInt f1("153295192598851061704259997818899114494",cs);
	SecureInt f2("54193344568995037984876256154647689091",cs);
	SecureInt fi("84529780082081314933245143442254705579",cs);
	SecureInt i("230376352776149990119331116494186351696",cs);
	SecureInt result("198621137501364187179819226768984514990",cs);

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

