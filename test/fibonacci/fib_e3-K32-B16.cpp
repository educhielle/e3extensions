#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 10
//#define NUM 7

int main()
{
	Cryptosystem cs("2197164737",16,"3508263183420736321",{"185993530900589620","3496513005262731562","1277857544767700844","124442537074148550","506177125263649944","69320891812803578","2892753392252510424","4475712615103642181","3882769721252254720","4521295990018826475","1082685596701884024","4166659311025824500","2254783354285754386","339681837069297886","2450691960717879900","1801919327988458811","2423524873951359761"},"2247435236610217341","3607391036223634136", libgDir, gFunctionName);

	SecureInt num("544879403320382832",cs);
	SecureInt f1("1739925661547481037",cs);
	SecureInt f2("2433495181120745403",cs);
	SecureInt fi("1030598142948604176",cs);
	SecureInt i("2710878240554699278",cs);
	SecureInt result("4092568991254957404",cs);

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

