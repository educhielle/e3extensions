/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

/*******************************************
* Note: this G function is not secure      *
        it is merely functional            *
        use it only for testing purpose    *
********************************************/

#ifndef FSTREAM_INCLUDED
	#define FSTREAM_INCLUDED
	#include <fstream>
#endif

#ifndef IOSTREAM_INCLUDED
	#define IOSTREAM_INCLUDED
	#include <iostream>
#endif

/*
#ifndef SENSITIVE_INFORMATION_INCLUDED
	#define SENSITIVE_INFORMATION_INCLUDED	
	#include "../preprocessor/sensitive_information.h"
#endif
*/

#ifndef UNUMBER_INCLUDED
	#define UNUMBER_INCLUDED
	#include "../unumber/unumberg.h"
#endif

#ifndef UTIL_INCLUDED
	#define UTIL_INCLUDED
	#include "../preprocessor/util.h"
#endif

#define FILENAME "CS.txt"

using namespace std;

//SensitiveInformation sinfo("104947","105613","3","2");
//SensitiveInformation sinfo("13","11","2","2");
//Unumber n = sinfo.getN(), n2 = sinfo.getN2();

Unumber fkf, _g, n, n2, xp1, xp2;
bool loaded = false;
bool sinfoReady = false;

Unumber congruence(Unumber, const Unumber &);
Unumber encrypt(const Unumber &);
bool leq(const Unumber);
void loadCryptosystemParams();
Unumber reencrypt(const Unumber &);

extern "C" Unumber g(Unumber x, Unumber y)
{
	if (!loaded) loadCryptosystemParams();
	
	//fkf = sinfo.fkf();
	Unumber ox = Unumber(x);
	ox.pow(fkf, n2);

	//Unumber zero = sinfo.encrypt(0);
	Unumber zero = encrypt(0);
	Unumber _y = reencrypt(y);

	//if (sinfo.leq(ox)) return zero;
	if (leq(ox)) return zero;

	return _y;
}

/* x % n */
Unumber congruence(Unumber x, const Unumber & n)
{
	if ( n.iszero() ) return x;

	Unumber nn(n);
	nn <<= 2;
	if (nn > x)
	{
		while (n < x) x -= n;
		return x;
	}

	x.divABRQ(n, &nn, 0);
	return nn;
}

Unumber encrypt(const Unumber & m)
{
	Unumber rN = invertibleRandom(2,n);
	rN.pow(n, n2);
	Unumber gm = _g;
	gm.pow(congruence(m, n), n2);
	//gm.pow(m, n2);
	Unumber x = rN.mul(gm, n2);
	
	return x;
}

/* Leq test */
/* Return true if an open value x is less or equal than zeor */
bool leq(const Unumber x)
{
	return ((x < xp1) || (xp2 < x));
}

void loadCryptosystemParams()
{
	ifstream in;
	in.open(FILENAME, ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string text = buffer.str();
	in.close();

	int semicolon[5];
	semicolon[0] = text.find(";") + 1;
	semicolon[1] = text.find(";", semicolon[0]) + 1;
	semicolon[2] = text.find(";", semicolon[1]) + 1;
	semicolon[3] = text.find(";", semicolon[2]) + 1;
	semicolon[4] = text.find(";", semicolon[3]) + 1;
	int newLine = text.find("\n") + 1;

	string strFKF = text.substr(semicolon[0], semicolon[1]-semicolon[0]-1);
	string strG   = text.substr(semicolon[1], semicolon[2]-semicolon[1]-1);
	string strN   = text.substr(semicolon[2], semicolon[3]-semicolon[2]-1);
	string strXp1 = text.substr(semicolon[3], semicolon[4]-semicolon[3]-1);
	string strXp2 = text.substr(semicolon[4], newLine     -semicolon[4]-1);

	fkf = Unumber(strFKF);
	_g = Unumber(strG);
	n = Unumber(strN);
	xp1 = Unumber(strXp1);
	xp2 = Unumber(strXp2);
	n2 = n*n;

	//cout << text << " [T]\n";
	//cout << fkf.str() << " " << _g.str() << " " << n.str() << " " << xp1.str() << " " << xp2.str() << " " << n2.str() << "\n";
	
	loaded = true;
}

/* Reencrypt a cyphertext with a random invertible number */
/* Following the equation x' = (r^N * x) % N2 */
Unumber reencrypt(const Unumber & x)
{
	Unumber y = invertibleRandom(2,n);
	y.pow(n,n2);
	y = y.mul(x,n2);
	return y;
}

