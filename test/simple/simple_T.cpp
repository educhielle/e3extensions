#include <iostream>
#include <fstream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

int main()
{
	cout << "Creating Cryptosystem\n";
	Cryptosystem cs("32293","12","431139774","551046301","292906477", libgDir, gFunctionName);
	cout << "Instantiating SecureInts\n";
	SecureInt a("537140728",cs), b("351644484",cs), c("539273510",cs), d("858291674",cs);
	cout << "Performing mathematical equation (it may take a while)\n";
	SecureInt r = a+b*c-d;
	cout << "Writing output file\n";
	ofstream out;
	out.open("output.txt", ofstream::out);
	out << r.str();
	out.close();

	return 0;
}

