#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

#define MAX_NUM 50
//#define NUM 5

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	Cryptosystem cs("13093204529582025677","8","69571172583426353044929568370145135413","62128510773125243273129175235977797807","121982519225682382116152032073306639130", libgDir, gFunctionName);

	SecureInt num("138352163400252317742945540289497725109",cs);
	SecureInt fact("107839117456290651373303712476517537228",cs);
	SecureInt i("17472933466090683792684296234428272537",cs);
	SecureInt result("90646966385541499773265028941398516818",cs);
	
	int counter = 1;

	do {
		cout << counter << "...\n";
		fact *= i;
		result += (i == num) * fact;
	} while (++counter != MAX_NUM);


	cout << "fact(" << fact.str() << ") = " << result.str() << "\n";

	return 0;
}

