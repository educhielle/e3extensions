/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

#include "secureint.h"

/*********************
 *     OPERATORS     *
 *********************/

/* Encrypted addition */
void SecureInt::operator+= (const SecureInt & param)
{
	x.eadd(param.x);
}

/* Encrypted subtraction */
void SecureInt::operator-= (const SecureInt & param)
{
	x.esub(param.x);
}

/* Encrypted multiplication */
void SecureInt::operator*= (const SecureInt& param)
{
	x.emuls(param.x);
}

/* Shift left */
void SecureInt::operator<<= (const SecureInt& param)
{
	x.esll(param.x);
}

/* Shift right */
void SecureInt::operator>>= (const SecureInt& param)
{
	x.esra(param.x);
}

/* Encrypted increment */
SecureInt SecureInt::operator++ ()
{
	x.einc();
}

/* Encrypted decrement */
/* Equivalent to a inverse followed by modular multiplication */
SecureInt SecureInt::operator-- ()
{
	x.edec();
}

/* Addition */
SecureInt operator+ (const SecureInt & n1, const SecureInt & n2)
{
	SecureInt r(n1); r += n2; return r;
}

/* Subtraction */
SecureInt operator- (const SecureInt & n1, const SecureInt & n2)
{
	SecureInt r(n1); r -= n2; return r;
}

/* Multiplication */
SecureInt operator* (const SecureInt & n1, const SecureInt & n2)
{
	SecureInt r(n1); r *= n2; return r;
}

/* Shift left */
SecureInt operator<< (const SecureInt & n1, const SecureInt & shift)
{
	SecureInt r(n1); r <<= shift; return r;
}

/* Shift right */
SecureInt operator>> (const SecureInt & n1, const SecureInt & shift)
{
	SecureInt r(n1); r >>= shift; return r;
}

/* Equal */
/* Compare if two encrypted numbers are equal */
SecureInt operator== (const SecureInt & n1, const SecureInt & n2)
{
	Unumber cmp;
	cmp.eeq(n1.x, n2.x);
	return SecureInt(cmp);
}

/* Different */
/* Compare if two encrypted numbers are different */
SecureInt operator!= (const SecureInt & n1, const SecureInt & n2)
{
	Unumber cmp;
	cmp.ene(n1.x, n2.x);
	return SecureInt(cmp);
}

/* Different */
/* Compare if two encrypted numbers are different */
SecureInt operator> (const SecureInt & n1, const SecureInt & n2)
{

}

/* Different */
/* Compare if two encrypted numbers are different */
SecureInt operator< (const SecureInt & n1, const SecureInt & n2)
{

}

/* Different */
/* Compare if two encrypted numbers are different */
SecureInt operator>= (const SecureInt & n1, const SecureInt & n2)
{
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
SecureInt operator<= (const SecureInt & n1, const SecureInt & n2)
{
}


/************************************
 *     PRIVATE OBJECT FUNCTIONS     *
 ************************************/


/***********************************
 *     PUBLIC OBJECT FUNCTIONS     *
 ***********************************/

/* Return the Cryptosystem */
/*Cryptosystem SecureInt::getCryptosystem() const
{
	return cryptosystem;
}*/

/* Return the cyphertext (x) */
Unumber SecureInt::getX() const
{
	return x;
}

/* Return the cyphertext in string format */
string SecureInt::str(unsigned base) const
{
	return x.str(base);
}


/************************************
 *     PRIVATE STATIC FUNCTIONS     *
 ************************************/


/***********************************
 *     PUBLIC STATIC FUNCTIONS     *
 ***********************************/

void SecureInt::setKey(Unumber pri, Unumber pub, Unumber mod, unsigned esize, unsigned dsize)
{
	Unumber::setKey(pri, pub, mod, esize, dsize);
}

SecureInt SecureInt::encrypt(unsigned long long m)
{
	Unumber x(m);
	x.enc();
	return SecureInt(x);
}
