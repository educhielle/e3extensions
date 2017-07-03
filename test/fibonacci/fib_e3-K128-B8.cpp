#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

#define MAX_NUM 50
//#define NUM 12

int main()
{
	Cryptosystem cs("201312838265554160844132015273888904957","8","17421406763982605312313940899821984873169990133076427017165362055665762215687","40112221501304937303899996709266736391735241787554875690253339544580145002850","36266147655130453810459886507255639413624692249515485906067905576834917431142", libgDir, gFunctionName);

	SecureInt num("23336632669614857148831342464631389268892846308697063728495907960806837747830",cs);
	SecureInt f1("206914772914997762369580053774600881427958647022652583945550351729242795975",cs);
	SecureInt f2("38145206486629308356016762689117882552460802926623916423423363845115459093",cs);
	SecureInt fi("15851080567448169412144724557587131290421154789085749570535361402789723970269",cs);
	SecureInt i("10319379881997432019327946963179050056529294234518792480715562001812407060346",cs);
	SecureInt result("10262919106098834370276265440103290258205457686305693022159914969783843364958",cs);

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

