#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 10
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("3577587161",16,"1981199664970374734",{"10225869863837045932","7755257098378456564","11280851123692990216","12237094677284940139","3544188784659744049","128852806088889998","11901949012079420397","6693885573864197212","6718846443475558488","8477742083360172779","6930484059470178091","4712952751298669191","3664770099197847270","2587950480487744455","1688742186397329252","82537861867787075","4826531826852130622"},"4723967122807386640","2798018037404119854", libgDir, gFunctionName);

	SecureInt num("12284162544169774179",cs);
	SecureInt fact("990409253255887640",cs);
	SecureInt i("355820886013938913",cs);
	SecureInt result("2939537817712645580",cs);
	
	int counter = 1;

	do {
		//cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
		++i;
	} while (++counter != MAX_NUM);

	cout << "fact( " << num.str() << " ) = " << result.str() << "\n";

	return 0;
}

