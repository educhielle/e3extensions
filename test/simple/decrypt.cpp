#include <fstream>
#include <iostream>
#include "../../src/preprocessor/sensitive_information.h"

#define FILENAME "CS.txt"

using namespace std;

Unumber p, q, k;

void loadCryptosystemParams();

int main()
{
	cout << "Loading Cryptosystem parameters\n";
	loadCryptosystemParams();
	cout << "Instantiating SensitiveInformation (to decrypt)\n";
	SensitiveInformation si(p,q,k);
	cout << "Reading encrypted value from output.txt\n";
	ifstream in;
	in.open("output.txt", ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string strEncValue = buffer.str();
	in.close();
	Unumber encValue(strEncValue);
	cout << "Decrypting\n";
	Unumber R, result;
	result = si.decrypt(encValue, &R);
	cout << "Result: " << result.str() << " (encrypted value: " << encValue.str() << ")\n";

	return 0;
}

void loadCryptosystemParams()
{
	ifstream in;
	in.open(FILENAME, ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string text = buffer.str();
	in.close();

	int semicolon[4];
	semicolon[0] = text.find(";") + 1;
	semicolon[1] = text.find(";", semicolon[0]) + 1;
	semicolon[2] = text.find(";", semicolon[1]) + 1;
	semicolon[3] = text.find(";", semicolon[2]) + 1;

	string strP   = text.substr(semicolon[0], semicolon[1]-semicolon[0]-1);
	string strQ   = text.substr(semicolon[1], semicolon[2]-semicolon[1]-1);
	string strK   = text.substr(semicolon[2], semicolon[3]-semicolon[2]-1);

	p = Unumber(strP);
	q = Unumber(strQ);
	k = Unumber(strK);
}

