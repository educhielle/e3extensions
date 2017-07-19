#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("26069",13,"279356300",{"277379309","432249006","23795779","673944129","639378007","221573008","107285967","219909120","397096310","101035571","473045281","442747001","92155420","105679822"},"507907545","251902657", libgDir, gFunctionName);

	SecureInt num("543371190",cs);
	SecureInt f1("113794841",cs);
	SecureInt f2("490710146",cs);
	SecureInt fi("301046195",cs);
	SecureInt i("590542093",cs);
	SecureInt result("145276031",cs);

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

