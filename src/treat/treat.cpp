#ifndef UNUMBER_INCLUDED
	#define UNUMBER_INCLUDED
	#include "../unumber/unumberg.h"
#endif

#ifndef IOSTREAM_INCLUDED
	#define IOSTREAM_INCLUDED
	#include <iostream>
#endif

#ifndef FSTREAM_INCLUDED
	#define FSTREAM_INCLUDED
	#include <fstream>
#endif

#ifndef REGEX_INCLUDED
	#define REGEX_INCLUDED	
	#include <regex>
#endif

#ifndef VECTOR_INCLUDED
	#define VECTOR_INCLUDED	
	#include <vector>
#endif

#ifndef SENSITIVE_INFORMATION_INCLUDED
	#define SENSITIVE_INFORMATION_INCLUDED	
	#include "../treat/sensitive_information.h"
#endif

using namespace std;

#define NUMBER_OF_CS_PARAMETERS 7
#define NUMBER_OF_SI_PARAMETERS 2

vector<string> csList;
vector<SensitiveInformation> sinfoList;
SensitiveInformation sinfo;

string calcNewParamsCS(string);
string calcNewParamsSI(string);
const vector<string> explode(const string &, const char &);
int findClosingBracket(const string &, int);
string findObjectNameBefore(const string &, int);
int indexOf(vector<string>, const string &);
bool isBlockComment(const string &, const int);
bool isComment(const string &, const int);
bool isLineComment(const string &, const int);
bool isSecureIntPrecompilerTag(const string &);
bool isValidPQ(const string &);
SensitiveInformation mountSensitiveInformation(string &);
Unumber prime();
Unumber random(Unumber, Unumber);
void trim(string &);

int main(int argc, char *argv[])
{
	while (argc-- > 1)
	{
		string filename = argv[argc];

		int dot = filename.find(".");
		string filenameOut = filename.substr(0,dot) + "_T" + filename.substr(dot);

		ifstream in;
		stringstream buffer;

		in.open(filename, ifstream::in);
		buffer << in.rdbuf();
		in.close();

		std::string code = buffer.str();

		// Cryptosystem
		cout << "\nCRYPTOSYSTEMs:\n";
		for (int csd = 0; (csd = code.find("Cryptosystem",csd)) != -1; csd++)
		{
			if (!isComment(code,csd))
			{
				int semicolon = code.find(";", csd);
				for (int csi; ((csi = code.find("(", csd)) != -1) && (csi < semicolon);)
				{
					int csf = findClosingBracket(code, csi+1);
					string line = code.substr(csd, csf-csd+1);

					string objName = code.substr(csd, csi-csd);
					int cso = objName.find_first_of(" \t");
					if (cso > 0) objName = objName.substr(cso);
					trim(objName);
					if (!objName.compare("Cryptosystem")) objName = findObjectNameBefore(code, csd);

					csi++;
					string params = code.substr(csi, csf-csi);
					string newParams = calcNewParamsCS(params);
					code = code.replace(csi, csf-csi, newParams);
					cout << "Object name: " << (objName.empty() ? "(no name)" : objName) << "\nParameters: " << newParams << "\n";
					csd = csf;

					if (params.compare(newParams))
					{
						if (!objName.empty())
						{
							csList.push_back(objName);
							sinfoList.push_back(sinfo);
						}
						Unumber f = sinfo.fkf();
						cout << "The fkf of '" << objName << "' is " << f.str() << ". Use it in the G function.\n";
					}
					cout << "\n";
				}
			}
		}
		
		// SecureInt
		cout << "\nSECUREINTs\n";
		for (int sid = 0; (sid = code.find("SecureInt",sid)) != -1; sid++)
		{
			if (!isComment(code,sid))
			{
				int semicolon = code.find(";", sid);
				for (int sii; ((sii = code.find("(", sid)) != -1) && (sii < semicolon);)
				{
					string objName = code.substr(sid, sii-sid);
					int sio = objName.find_first_of(" \t");
					if (sio > 0) objName = objName.substr(sio);
					if (!objName.compare("SecureInt")) objName = findObjectNameBefore(code, sid);
					///int sif = code.find(")", sii);
					int sif = findClosingBracket(code, sii+1);

					sii++;
					string params = code.substr(sii, sif-sii);
					string newParams = calcNewParamsSI(params);
					code = code.replace(sii, sif-sii, newParams);
					sid = sif;
					cout << "Object name: " << (objName.empty() ? "(no name)" : objName) << "\nParameters: " << newParams << "\n\n";
				}
			}
		}
	
		ofstream out;
		out.open(filenameOut, ofstream::out);
		out << code;
		out.close();
	}

	return 0;
}

string calcNewParamsCS(string params)
{
	Unumber p,q,k,rnd;
	string strPQ, strBeta, strTwoToBeta, strEnc0, strEnc1, libgFilename, libgFunction;

	vector<string> v{explode(params,',')};
	switch (v.size())
	{
		case NUMBER_OF_CS_PARAMETERS:
			strPQ = v[0];
			strBeta = v[1];
			strTwoToBeta = v[2];
			strEnc0 = v[3];
			strEnc1 = v[4];
			libgFilename = v[5];
			libgFunction = v[6];
			break;
		default:
			return params;
	}

	if (!isValidPQ(strPQ)) return params;

	try
	{
		sinfo = mountSensitiveInformation(strPQ);
		
		trim(strBeta);
		if (strBeta.compare("__BETA__"))
		{
			Unumber b(strBeta);
			sinfo.setBeta(b.to_ull());
		}

		Unumber n = sinfo.getN();
		Unumber beta = sinfo.getBeta();
		Unumber twoToBeta = sinfo.getTwoToBeta();
		Unumber zero = sinfo.encrypt(Unumber(0));
		Unumber one = sinfo.encrypt(Unumber(1));

		string newParams = "\"" + n.str() + "\",\"" + beta.str() + "\",\""
			+ twoToBeta.str() + "\",\"" + zero.str() + "\",\"" + one.str() + "\","
			+ libgFilename + "," + libgFunction; // + "," + libgInit;

		return newParams;
	}
	catch (std::exception & e) { }

	return params;
}

string calcNewParamsSI(string params)
{
	vector<string> v{explode(params,',')};
	if (v.size() != NUMBER_OF_SI_PARAMETERS) return params;

	string strValue = v[0];
	string csName = v[1];

	if (!isSecureIntPrecompilerTag(strValue)) return params;

	try
	{
		int posI = strValue.find("(");
		int posF = strValue.find(")", posI);
		strValue = strValue.substr(posI+1, posF-posI-1);
		trim(strValue);
	
		Unumber value (strValue);

		int pos = indexOf(csList, csName);
		if (pos == -1) return params;

		sinfo = sinfoList[pos];
		value = sinfo.encrypt(value);

		string newParams = "\"" + value.str() + "\"," + csName;
		return newParams;
	}
	catch (std::exception & e) { }
	
	return params;
}

const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

int findClosingBracket(const string & code, int init)
{
	int countOpen = 1, countClose = 0;
	int posOpen, posClose;

	while (countOpen > countClose)
	{
		posOpen = code.find("(", init);
		posClose = code.find(")", init);

		if ((posOpen == -1) && (posClose == -1)) return -1;

		if ((posOpen == -1) || (posClose < posOpen))
		{
			if (!isComment(code, posClose)) countClose++;
			init = posClose + 1;
		}
		else
		{
			if (!isComment(code, posOpen)) countOpen++;
			init = posOpen + 1;
		}
	}

	return posClose;
}

string findObjectNameBefore(const string & code, int posF)
{
	int posI = code.rfind(";", posF);
	if (posI == -1) posI = 0;
	int posE = code.find("=", posI);
	
	string str = "";
	if (posE > posI)
	{
		str = code.substr(posI+1,posE-posI-1);
		trim(str);
	}
	
	return str;
}

int indexOf(vector<string> v, const string & elem)
{
	for (int i = 0; (unsigned) i < v.size(); i++)
	{
		if (elem.compare(v[i]) == 0) return i;
	}

	return -1;
}

bool isBlockComment(const string & code, const int pos)
{
	int blockCommentStartBefore = code.rfind("/*", pos);
	int blockCommentEndBefore = code.rfind("*/", pos);
	if (blockCommentStartBefore <= blockCommentEndBefore) return false;
	
	return true;
}

bool isComment(const string & code, const int pos)
{
	return (isLineComment(code, pos) || isBlockComment(code, pos));
}

bool isLineComment(const string & code, const int pos)
{
	int newLineBefore = code.rfind("\n", pos) + 1;
	int newLineAfter = code.find("\n", pos);

	string line;
	if (newLineAfter == -1) code.substr(newLineBefore);
	else line = code.substr(newLineBefore, newLineAfter - newLineBefore);
	int lineComment = line.find("//");
	
	return ((lineComment != -1) && (lineComment < newLineBefore));
}

bool isSecureIntPrecompilerTag(const string & str)
{
	std::regex re("__N\\([0-9]+\\)__");
	std::cmatch m;
	return std::regex_match(str.c_str(), m, re);
}

bool isValidPQ(const string & pqkrnd)
{
	try
	{
		string part = pqkrnd.substr(0,4);
		if (part.compare("__PQ")) return false;

		part = pqkrnd.substr(pqkrnd.length()-2, pqkrnd.length());
		if (part.compare("__")) return false;

		return true; //ish
	}
	catch (const std::exception & e) { } 

	return false;
}

SensitiveInformation mountSensitiveInformation(string & pqkrnd)
{
	try
	{
		int posI = pqkrnd.find("(");
		int posF = pqkrnd.find(")", posI);
		string strP = pqkrnd.substr(posI+1, posF-posI-1);

		posI = pqkrnd.find("(", posF);
		posF = pqkrnd.find(")", posI);
		string strQ = pqkrnd.substr(posI+1, posF-posI-1);

		posI = pqkrnd.find("(", posF);
		posF = pqkrnd.find(")", posI);
		string strK = pqkrnd.substr(posI+1, posF-posI-1);

		posI = pqkrnd.find("(", posF);
		posF = pqkrnd.find(")", posI);
		string strRnd = pqkrnd.substr(posI+1, posF-posI-1);

		trim(strP);
		trim(strQ);
		trim(strK);
		trim(strRnd);

		Unumber p   = (  strP.empty() ? prime()       : Unumber(strP));
		Unumber q   = (  strQ.empty() ? prime()       : Unumber(strQ));
		Unumber pq = p*q;
		Unumber k   = (  strK.empty() ? random(2, pq) : Unumber(strK));
		Unumber rnd = (strRnd.empty() ? random(2, pq) : Unumber(strRnd));

		cout << "P: " << p.str() << "\tQ: " << q.str() << "\tK: " << k.str() << "\tRND: " << rnd.str() << "\n";

		return SensitiveInformation(p,q,k,rnd);
	}
	catch (std::exception & e) { }

	return SensitiveInformation();
}

Unumber prime()
{
	return Unumber(13);
}

Unumber random(Unumber from, Unumber to)
{
	return from;
}

void trim(string & s)
{
	size_t p = s.find_first_not_of(" \t\n");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p+1);
}

