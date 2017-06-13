#include <iostream>

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

#include "../preprocessor/big_random.h"
#include "libg.h"
#include "../unumber/unumberg.h"

#ifndef STATIC_LIBG
	#include <fstream>
	#include <iostream>

	#define FILENAME "CS.txt"

	using namespace std;

	bool loaded = false;
#endif

Unumber fkf(3480), _g(430), n(143), n2(20449), xp1(144), xp2(18304);

/* G function */
/* if the unencryption of x is less or equal zero
 * 	return the encryption of zero
 * else return the reencryption of y */	
Unumber libg(Unumber x, Unumber y)
{
#ifndef HWACC
#ifndef STATIC_LIBG
	if (!loaded) loadCryptosystemParams();
#endif
	Unumber ox = Unumber(x);
	ox.pow(fkf, n2);

	Unumber zero = encrypt(0);
	Unumber _y = reencrypt(y);

	if (leq(ox)) return zero;

	return _y;
#else
	mpz_t mpz_x, mpz_y, mpz_r;
	mpz_init(mpz_x);
	mpz_init(mpz_y);
	mpz_init(mpz_r);
	mpz_set_str(mpz_x, x.str().c_str(), 10);
	mpz_set_str(mpz_y, y.str().c_str(), 10);

	unsigned length = 64;
	size_t *countp;
	unsigned order = 1;
	unsigned endianess = 1;
	unsigned nails = 0;
	unsigned mA[length], mB[length], mD[length];
	unsigned size = length * sizeof(unsigned);

	if (mpz_cmp_ui(mpz_x, 0)) mpz_export(mA, countp, order, size, endianess, nails, mpz_x);
	else for (unsigned i = 0; i < length; i++) mA[i] = 0;

	if (mpz_cmp_ui(mpz_y, 0)) mpz_export(mB, countp, order, size, endianess, nails, mpz_y);
	else for (unsigned i = 0; i < length; i++) mB[i] = 0;

	Unumber::mtmr2048_m1(mA);
	Unumber::mtmr2048_m2(mB);

	__asm__ ("moma.g2048 m0,m1,m2");

	Unumber::mfmr2048_m0(mD);

	mpz_import(mpz_r, length, order, sizeof(unsigned), endianess, nails, mD);

	Unumber r (mpz_get_str(NULL, 10, mpz_r));
	return r;
#endif
}

/* Return (x % n) */
/* It is used to make sure x < n */
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

/* Encrypt following equation x = r^N * (1 + N*k*m) % N2 */
Unumber encrypt(const Unumber & m)
{
	Unumber rN = invertibleRandom(2,n);
	rN.pow(n, n2); //r^N

	Unumber gm = _g;
	// gm.pow(congruence(m, n), n2); // g^m % N2 -- replaced by the next line
	gm = (congruence(m, n) * (gm - 1) + 1) % n2; // (1 + N*k*m) % N2

	Unumber x = rN.mul(gm, n2); // r^N * (1 + N*k*m) % N2
	
	return x;
}

/* Leq test */
/* Return true if an open value x is less or equal than zero */
bool leq(const Unumber x)
{
	return ((x < xp1) || (xp2 < x));
}

/* Load Cryptosystem parameters from CS.txt file */
#ifndef STATIC_LIBG
void loadCryptosystemParams()
{
	ifstream in;
	in.open(FILENAME, ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string text = buffer.str();
	in.close();

	int semicolon[8];
	semicolon[0] = text.find(";") + 1;
	semicolon[1] = text.find(";", semicolon[0]) + 1;
	semicolon[2] = text.find(";", semicolon[1]) + 1;
	semicolon[3] = text.find(";", semicolon[2]) + 1;
	semicolon[4] = text.find(";", semicolon[3]) + 1;
	semicolon[5] = text.find(";", semicolon[4]) + 1;
	semicolon[6] = text.find(";", semicolon[5]) + 1;
	semicolon[7] = text.find(";", semicolon[6]) + 1;
	int newLine = text.find("\n") + 1;

	//string strP   = text.substr(semicolon[0], semicolon[1]-semicolon[0]-1);
	//string strQ   = text.substr(semicolon[1], semicolon[2]-semicolon[1]-1);
	//string strK   = text.substr(semicolon[2], semicolon[3]-semicolon[2]-1);
	string strFKF = text.substr(semicolon[3], semicolon[4]-semicolon[3]-1);
	string strG   = text.substr(semicolon[4], semicolon[5]-semicolon[4]-1);
	string strN   = text.substr(semicolon[5], semicolon[6]-semicolon[5]-1);
	string strXp1 = text.substr(semicolon[6], semicolon[7]-semicolon[6]-1);
	string strXp2 = text.substr(semicolon[7], newLine     -semicolon[7]-1);

	//cout << text << "\n";

	//p = Unumber(strP);
	//q = Unumber(strQ);
	//k = Unumber(strK);
	fkf = Unumber(strFKF);
	_g = Unumber(strG);
	n = Unumber(strN);
	xp1 = Unumber(strXp1);
	xp2 = Unumber(strXp2);
	n2 = n*n;
	
	loaded = true;
}
#endif

/* Reencrypt a cyphertext with a random invertible number */
/* Following the equation x' = (r^N * x) % N2 */
Unumber reencrypt(const Unumber & x)
{
	Unumber y = invertibleRandom(2,n);
	y.pow(n,n2);
	y = y.mul(x,n2);
	return y;
}

