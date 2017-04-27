/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMA lab                                 *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

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

#ifndef STDIO_INCLUDED
	#define STDIO_INCLUDED	
	#include <stdio.h>
#endif

#ifndef STDLIB_INCLUDED
	#define STDLIB_INCLUDED	
	#include <stdlib.h>
#endif

#ifndef DLFCN_INCLUDED
	#define DLFCN_INCLUDED	
	#include <dlfcn.h>
#endif

class Cryptosystem
{
	typedef Unumber (*libG_t)(Unumber, Unumber);

    /* Variables */
    private:
	Unumber n, n2, beta, twoToBeta, zero, one; //, xp1, xp2; //-- leq test removed
	//Unumber a2, b2;
	unsigned high_bit_posN; //, high_bit_posN2;
	Unumber rndN;

	string libgFilename, libgFunction, libgInit;
	void* libgHandle;
	libG_t externG;
	

    /* Constructors */
    public:	
	Cryptosystem() {}
	Cryptosystem(const Cryptosystem &);
	Cryptosystem(const string &, const string &, const string &, const string &, const string &, const string &, const string &);
	Cryptosystem(const Unumber, const Unumber, const Unumber, const Unumber, const Unumber, const string &, const string &);
	Cryptosystem(unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long, const string &, const string &);

    /* Private functions */
    private:
	//Unumber congruence(Unumber, const Unumber &) const;
	void init();
	void next_rnd();

    /* Public functions */
    public:
	void close();
	Unumber g(Unumber, Unumber) const;
	Unumber getBeta() const;
	Unumber getN() const;
	Unumber getN2() const;
	Unumber getOne() const;
	Unumber getTwoToBeta() const;
	Unumber getZero() const;
	Unumber invertibleRandom() const;
	//bool leq(Unumber) const;
        Unumber random() { next_rnd(); return rndN; }
	Unumber reencrypt(const Unumber) const;
};

/*******************************************
 *     STATIC VARIABLES INITIALIZATION     *
 *******************************************/

//Unumber Cryptosystem::rndN = 0;


/************************
 *     CONSTRUCTORS     *
 ************************/

inline
Cryptosystem::Cryptosystem(const Cryptosystem & param)
{
	this->n = param.n;
//	this->n2 = param.n2;
	this->beta = param.beta;
	this->twoToBeta = param.twoToBeta;
	this->zero = param.zero;
	this->one = param.one;
//	this->xp1 = param.xp1;
//	this->xp2 = param.xp2;
	this->libgFilename = param.libgFilename;
	this->libgFunction = param.libgFunction;
	//this->libgInit = param.libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(const string & n, const string & beta, const string & twoToBeta, const string & zero, const string & one, const string & libgFilename, const string & libgFunction)
{
	this->n = Unumber(n);
//	this->n2 = Unumber(n2);
	this->beta = Unumber(beta);
	this->twoToBeta = Unumber(twoToBeta);
	this->zero = Unumber(zero);
	this->one = Unumber(one);
//	this->xp1 = Unumber(xp1);
//	this->xp2 = Unumber(xp2);
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(const Unumber n, const Unumber beta, const Unumber twoToBeta, const Unumber zero, const Unumber one, const string & libgFilename, const string & libgFunction)
{
	this->n = n;
//	this->n2 = n2;
	this->beta = beta;
	this->twoToBeta = twoToBeta;
	this->zero = zero;
	this->one = one;
//	this->xp1 = xp1;
//	this->xp2 = xp2;
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(unsigned long long n, unsigned long long beta, unsigned long long twoToBeta, unsigned long long zero, unsigned long long one, const string & libgFilename, const string & libgFunction)
{
	this->n = Unumber(n);
//	this->n2 = Unumber(n2);
	this->beta = Unumber(beta);
	this->twoToBeta = Unumber(twoToBeta);
	this->zero = Unumber(zero);
	this->one = Unumber(one);
//	this->xp1 = Unumber(xp1);
//	this->xp2 = Unumber(xp2);
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}


/*****************************
 *     PRIVATE FUNCTIONS     *
 *****************************/

void Cryptosystem::next_rnd()
{
	if (rndN.iszero()) throw "Rnd used, but not initialised: set random seed";
	rndN = rndN.mul(rndN, n2); // for rnd need N, for rndN need N2
}

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

	/*x = n2;
	while (x != 0) { x >>= 1; high_bit_posN2++; }
	high_bit_posN2--;*/

	/* loading external G function */
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
	externG = (libG_t) dlsym(libgHandle, libgFunction.c_str());
	const char *dlsym_error = dlerror();
	if (dlsym_error)
	{
		cerr << dlsym_error << "\n";
		dlclose(libgHandle);
		exit(1);
	}
}

/****************************
 *     PUBLIC FUNCTIONS     *
 ****************************/

void Cryptosystem::close()
{
	dlclose(libgHandle);
}

/* G function */
Unumber Cryptosystem::g(Unumber x, Unumber y) const
{
	return externG(x, y);
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
	std::mt19937_64 mt64(rd());
	
	Unumber number(0);

	while (true)
	{
		number = 0;
		unsigned count = 0;
		while (count < high_bit_posN)
		{
			count += 64;
			number <<= 64;
			number += mt64();
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

/* Leq test */
/* Return true if an open value x is less or equal than zeor */
/*bool Cryptosystem::leq(Unumber x) const
{
	return ((x < xp1) || (xp2 < x));
}*/

/* Reencrypt a cyphertext with a random invertible number */
/* Following the equation x' = (r^N * x) % N2 */
Unumber Cryptosystem::reencrypt(const Unumber x) const
{
	Unumber y = invertibleRandom();
	//Unumber y = random();
	y.pow(n,n2);
	y = y.mul(x,n2);
	return y;
}

