#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("7773839135390654929","8","27725447421788449180226609586165638285","58466247673786056703559912563324639480","24341451452823187191000880819068226745", libgDir, gFunctionName);

	SecureInt num("52751517458654764604131273326079541051",cs);
	SecureInt fact("3882848480832040893511472925182939875",cs);
	SecureInt i("31625739961455910455218512903954280518",cs);
	SecureInt result("20389958826721707776364096971660969126",cs);
	
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

