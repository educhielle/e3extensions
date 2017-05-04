#include <iostream>
#include <fstream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "../../lib/libg.so";
string gFunctionName = "g";

int main()
{
	cout << "Creating Cryptosystem\n";
	Cryptosystem cs("69469","11","4524802742","559168206","4743972090", libgDir, gFunctionName);
	cout << "Instantiating SecureInts\n";
	SecureInt a("4801262325",cs), b("2531365604",cs), c("3597505120",cs), d("2213363918",cs);
	cout << "Performing mathematical equation (it may take a while)\n";
	SecureInt r = a+b*c-d;
	cout << "Writing output file\n";
	ofstream out;
	out.open("output.txt", ofstream::out);
	out << r.str();
	out.close();

	return 0;
}

