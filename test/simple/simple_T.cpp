#include <iostream>
#include <fstream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "../../lib/libg.so";
string gFunctionName = "g";

int main()
{
	cout << "Creating Cryptosystem\n";
	Cryptosystem cs("223609","15","34896776909","10672121536","1363186336", libgDir, gFunctionName);
	cout << "Instantiating SecureInts\n";
	SecureInt a("13487715926",cs), b("21144370402",cs), c("18944911666",cs), d("12857354039",cs);
	cout << "Performing mathematical equation (it may take a while)\n";
	SecureInt r = a+b*c-d;
	cout << "Writing output file\n";
	ofstream out;
	out.open("output.txt", ofstream::out);
	out << r.str();
	out.close();

	return 0;
}

