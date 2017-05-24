/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

#ifndef __CRYPTOSYSTEM_H__
#define __CRYPTOSYSTEM_H__

#ifndef STATIC_LIBG
	#include <dlfcn.h>
#endif

#include <iostream>
#include "../unumber/unumberg.h"

#ifdef ARCH64
	#define WORD_SIZE 64
#else
	#define WORD_SIZE 32
#endif

class Cryptosystem
{
#ifndef STATIC_LIBG
	typedef Unumber (*libG_t)(Unumber, Unumber);
#endif

    /* Variables */
    private:
	Unumber n, n2, beta, twoToBeta, zero, one;
	unsigned high_bit_posN; //, high_bit_posN2;
	Unumber rndN;

	string libgFilename, libgFunction, libgInit;
#ifndef STATIC_LIBG
	void* libgHandle;
	libG_t libg;
#endif
	
    /* Constructors */
    public:	
	Cryptosystem() {}
	Cryptosystem(const Cryptosystem &);
	Cryptosystem(const string &, const string &, const string &, const string &, const string &, const string &, const string &);
	Cryptosystem(const Unumber, const Unumber, const Unumber, const Unumber, const Unumber, const string &, const string &);
	Cryptosystem(unsigned long long, unsigned long long, unsigned long long, unsigned long long, unsigned long long, const string &, const string &);

    /* Private functions */
    private:
	void init();

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
	Unumber reencrypt(const Unumber) const;
};

/************************
 *     CONSTRUCTORS     *
 ************************/

inline
Cryptosystem::Cryptosystem(const Cryptosystem & param)
{
	this->n = param.n;
	this->beta = param.beta;
	this->twoToBeta = param.twoToBeta;
	this->zero = param.zero;
	this->one = param.one;
	this->libgFilename = param.libgFilename;
	this->libgFunction = param.libgFunction;
	//this->libgInit = param.libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(const string & n, const string & beta, const string & twoToBeta, const string & zero, const string & one, const string & libgFilename, const string & libgFunction)
{
	this->n = Unumber(n);
	this->beta = Unumber(beta);
	this->twoToBeta = Unumber(twoToBeta);
	this->zero = Unumber(zero);
	this->one = Unumber(one);
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(const Unumber n, const Unumber beta, const Unumber twoToBeta, const Unumber zero, const Unumber one, const string & libgFilename, const string & libgFunction)
{
	this->n = n;
	this->beta = beta;
	this->twoToBeta = twoToBeta;
	this->zero = zero;
	this->one = one;
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}

inline
Cryptosystem::Cryptosystem(unsigned long long n, unsigned long long beta, unsigned long long twoToBeta, unsigned long long zero, unsigned long long one, const string & libgFilename, const string & libgFunction)
{
	this->n = Unumber(n);
	this->beta = Unumber(beta);
	this->twoToBeta = Unumber(twoToBeta);
	this->zero = Unumber(zero);
	this->one = Unumber(one);
	this->libgFilename = libgFilename;
	this->libgFunction = libgFunction;
	//this->libgInit = libgInit;

	init();
}

#endif

