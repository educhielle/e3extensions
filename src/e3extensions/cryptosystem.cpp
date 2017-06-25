//#include "statsg.h"

/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

#include "cryptosystem.h"
#include <random>

#ifdef STATIC_LIBG
	#include "libg.h"
/*	#include "../libg/libg.cpp"
	#define QUOTEME(M)	#M
	#define INCLUDE_FILE(M)	QUOTEME(M)
	#include INCLUDE_FILE(STATIC_LIBG) */
#endif

#ifdef FAST_RANDOM
unsigned Cryptosystem::idCount = 0;
Unumber Cryptosystem::rndN[CS_LIMIT];
#endif

/*****************************
 *     PRIVATE FUNCTIONS     *
 *****************************/

/* Initialize */
/* Find the high bit position of (n-1) */
/* Linking external G function */
void Cryptosystem::init()
{
	n2 = n * n;

	high_bit_posN = 0;
	Unumber x = n - 1;
	while (x != 0) { x >>= 1; high_bit_posN++; }
	high_bit_posN--;
#ifdef FAST_RANDOM
	if (id == 0)
	{
		idCount = (idCount + 1) % CS_LIMIT;
		id = idCount;
	}
#endif
	/*x = n2;
	while (x != 0) { x >>= 1; high_bit_posN2++; }
	high_bit_posN2--;*/

	/* loading external G function */
#ifndef STATIC_LIBG
	using std::cerr;
 
	// Find library and associate to handle
	
	libgHandle = dlopen(libgFilename.c_str(), RTLD_NOW);
	if (!libgHandle)
	{
		cerr << dlerror() << "\n";
		exit(1);
	}
	dlerror();

	// Find G function and link it
	libg = (libG_t) dlsym(libgHandle, libgFunction.c_str());
	const char *dlsym_error = dlerror();
	if (dlsym_error)
	{
		cerr << dlsym_error << "\n";
		dlclose(libgHandle);
		exit(1);
	}
#endif
}

/****************************
 *     PUBLIC FUNCTIONS     *
 ****************************/

void Cryptosystem::close()
{
#ifndef STATIC_LIBG
	dlclose(libgHandle);
#endif
}

/* G function */
Unumber Cryptosystem::g(Unumber x, Unumber y) const
{
	/*stats_g_counter++;*/
	return libg(x, y);
}

/* Return Beta */
Unumber Cryptosystem::getBeta() const
{
	return beta;
}

/* Return N */
Unumber Cryptosystem::getN() const
{
	return n;
}

/* Return N2 */
Unumber Cryptosystem::getN2() const
{
	return n2;
}

/* Return reencrypted one */
Unumber Cryptosystem::getOne() const
{
	return reencrypt(one);
}

/* Return reencrypted 2^Beta */
Unumber Cryptosystem::getTwoToBeta() const
{
	return reencrypt(twoToBeta);
}

/* Return reencrypted zero */
Unumber Cryptosystem::getZero() const
{
	return reencrypt(zero);
}

/* Invertible Random */
/* Generate an invetible random number */
Unumber Cryptosystem::invertibleRandom() const
{
	std::random_device rd;
#ifdef ARCH64
	std::mt19937_64 mt(rd());
#else
	std::mt19937 mt(rd());
#endif
	
	Unumber number(0);
	while (true)
	{
		number = 0;
		unsigned count = 0;
		while (count < high_bit_posN)
		{
			count += WORD_SIZE;
			number <<= WORD_SIZE;
			number += mt();
		}

		/* "count - high_bit_posN - 1" guarantees random numbers [1,n-1].
		 * However, any random number > (n-1) needs to be ignored.
		 * If "count - high_bit_posN" is used instead,
		 * the range of random numbers is [1,x], where x < (n-1),
		 * but it is faster. */
		unsigned shift = count - high_bit_posN - 1;
		number >>= shift;

		/* the number is valid if it is a number in the range [1,n-1]
		 * and its gcd with n is one */
		if ((number < n) && (ma::gcd(number, n) == 1)) break;
	}

	return number;
}

/* Reencrypt a cyphertext with a random invertible number */
/* Following the equation x' = (r^N * x) % N2 */
Unumber Cryptosystem::reencrypt(const Unumber x) const
{
std::cout << "CS::reencrypt i\n";
#ifdef FAST_RANDOM
	if (rndN[id] == 0)
	{
		rndN[id] = invertibleRandom();
		rndN[id].pow(n,n2);
	}
	else
	{
		rndN[id].mul(rndN[id],n2);
	}

	Unumber y = rndN[id].mul(x,n2);
#else
	Unumber y = invertibleRandom();
	y.pow(n,n2);
	y = y.mul(x,n2);
#endif
std::cout << "CS::reencrypt f\n";
	return y;
}
/*
void Cryptosystem::prita()
{
	std::cout << "G calls: " << stats_g_counter << "\n";
}
*/

