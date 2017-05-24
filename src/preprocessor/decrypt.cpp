/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

#include <fstream>
#include <iostream>
#include "sensitive_information.h"
#include "util.h"

using namespace std;

void decrypt(string, string, SensitiveInformation);
SensitiveInformation loadCryptosystemParams(string);

int main(int argc, char *argv[])
{
	if (argc <= 3)
	{
		cout << "Invalid arguments.\n";
		return 1;
	}

	string dataInFilename = argv[1];
	string dataOutFilename = argv[2];
	string cryptosystemFilename = argv[3];

	// Loading Cryptosystem parameters and Instantiating SensitiveInformation
	SensitiveInformation sinfo = loadCryptosystemParams(cryptosystemFilename);

	decrypt(dataInFilename, dataOutFilename, sinfo);

	return 0;
}

/* Read filenameIn, decrypts its content by line and write to the filenameOut */
void decrypt(string filenameIn, string filenameOut, SensitiveInformation sinfo)
{
	ifstream in;
	ofstream out;
	in.open(filenameIn, ifstream::in);
	out.open(filenameOut, ofstream::out);
	
	Unumber R, result;
	string line;

	getline(in, line);
	while (in)
	{
		trim(line);
		if (!line.empty())
		{
			Unumber encValue (line);
			result = sinfo.decrypt(encValue, &R);
			out << result.str();
		}
		out << "\n";
		getline(in, line);
	}

	in.close();
	out.close();
}

/* Read and parse the cryptosystem file, usually CS.txt. */
/* And creates a SensitiveInformation file used for decryption */
SensitiveInformation loadCryptosystemParams(string filename)
{
	ifstream in;
	in.open(filename, ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string text = buffer.str();
	in.close();

	int semicolon[4];
	semicolon[0] = text.find(";") + 1;
	semicolon[1] = text.find(";", semicolon[0]) + 1;
	semicolon[2] = text.find(";", semicolon[1]) + 1;
	semicolon[3] = text.find(";", semicolon[2]) + 1;

	string strP = text.substr(semicolon[0], semicolon[1]-semicolon[0]-1);
	string strQ = text.substr(semicolon[1], semicolon[2]-semicolon[1]-1);
	string strK = text.substr(semicolon[2], semicolon[3]-semicolon[2]-1);

	Unumber p,q,k;
	p = Unumber(strP);
	q = Unumber(strQ);
	k = Unumber(strK);

	return SensitiveInformation(p,q,k);
}

