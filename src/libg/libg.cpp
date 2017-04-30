#ifndef UNUMBER_INCLUDED
	#define UNUMBER_INCLUDED
	#include "../unumber/unumberg.h"
#endif

#ifndef IOSTREAM_INCLUDED
	#define IOSTREAM_INCLUDED
	#include <iostream>
#endif

#ifndef RANDOM_INCLUDED
	#define RANDOM_INCLUDED
	#include <random>
#endif

#ifndef SENSITIVE_INFORMATION_INCLUDED
	#define SENSITIVE_INFORMATION_INCLUDED	
	#include "../preprocessor/sensitive_information.h"
#endif

#ifndef UTIL_INCLUDED
	#define UTIL_INCLUDED
	#include "../preprocessor/util.h"
#endif

#define BETA 3
//#define FKF "66213691388699565672"

//SensitiveInformation sinfo("104947","105613","3","2");
//SensitiveInformation sinfo("13","11","2","2");
SensitiveInformation sinfo("13","11","2","2");
Unumber n = sinfo.getN(), n2 = sinfo.getN2();
unsigned high_bit_posN = sinfo.getHighBitPosN();
bool sinfoReady = false;
//Unumber xp1, xp2;

Unumber invertibleRandom();
bool leq(Unumber);
Unumber reencrypt(const Unumber);

extern "C" Unumber g(Unumber x, Unumber y)
{
	//if (!sinfoReady) { sinfo.setBeta(BETA); sinfoReady = true; }
	//Unumber fkf (FKF);
	Unumber fkf = sinfo.fkf();
	Unumber ox = Unumber(x);
	ox.pow(fkf, n2);
	Unumber zero = sinfo.encrypt(0);
	Unumber _y = reencrypt(y);

	if (sinfo.leq(ox)) return zero;

	return _y;
}

/* Reencrypt a cyphertext with a random invertible number */
/* Following the equation x' = (r^N * x) % N2 */
Unumber reencrypt(const Unumber x)
{
	Unumber y = invertibleRandom(2,n);
	y.pow(n,n2);
	y = y.mul(x,n2);
	return y;
}

