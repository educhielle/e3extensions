/*******************************************
* New York University in Abu Dhabi (NYUAD) *
* MoMAlab                                  *
* Author: Eduardo Chielle                  *
* eduardo.chielle@nyu.edu        2016-2017 *
********************************************/

#ifndef __SECUREINT_H__
#define __SECUREINT_H__

#include "cryptosystem.h"

class SecureInt
{
    /* Variables */
    private:
	Unumber x;
	Cryptosystem cryptosystem;

    public:
	enum StringType { Binary, Decimal };

    /* Constructors */
    public:
	SecureInt() {}
	SecureInt(const SecureInt &);
	SecureInt(const Unumber, const Cryptosystem);
	SecureInt(const string &, const Cryptosystem);
	SecureInt(const string &, unsigned, const Cryptosystem);
	SecureInt(const string &, StringType, const Cryptosystem);
	SecureInt(const string &, Unumber::StringType, const Cryptosystem);
	SecureInt(unsigned long long, const Cryptosystem);

    /* Operators */
    public:
	void operator+= (const SecureInt &);
	void operator-= (const SecureInt &);
	void operator*= (const SecureInt &);
	void operator<<= (unsigned);
	void operator>>= (unsigned);
	
	friend SecureInt operator+ (const SecureInt & n1, const SecureInt & n2)
	{ SecureInt r(n1); r += n2; return r; }

	friend SecureInt operator+ (const SecureInt & n1)
	{ return n1; }

	friend SecureInt operator- (const SecureInt & n1, const SecureInt & n2)
	{ SecureInt r(n1); r -= n2; return r; }

	friend SecureInt operator- (const SecureInt & n1)
	{ return SecureInt::invert(n1); }

	friend SecureInt operator* (const SecureInt & n1, const SecureInt & n2)
	{ SecureInt r(n1); r *= n2; return r; }

	friend SecureInt operator== (const SecureInt &, const SecureInt &);

	friend SecureInt operator!= (const SecureInt &, const SecureInt &);

	friend SecureInt operator<< (const SecureInt & n1, unsigned shift)
	{ SecureInt r(n1); r <<= shift; return r; }

	friend SecureInt operator>> (const SecureInt & n1, unsigned shift)
	{ SecureInt r(n1); r >>= shift; return r; }
	
    /* Private object functions */
    private:
	SecureInt div2();
	SecureInt half2();

    /* Public object functions */
    public:
	Cryptosystem getCryptosystem() const;
	SecureInt g(const SecureInt &) const;
	Unumber getN() const;
	Unumber getN2() const;
	Unumber getX() const;
	SecureInt invert() const;
	string str(unsigned) const;

    /* Private static functions */
    private:
	static SecureInt invert(const SecureInt &);

    /* Public static functions */
    public:
	static SecureInt g(const SecureInt &, const SecureInt &);
	static SecureInt G(const SecureInt &, const SecureInt &);
};

/************************
 *     CONSTRUCTORS     *
 ************************/

inline
SecureInt::SecureInt(const SecureInt & param)
{
	this->x = param.x;
	this->cryptosystem = param.cryptosystem;
}

inline
SecureInt::SecureInt(const Unumber x, const Cryptosystem cryptosystem)
{
	this->x = x;
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, const Cryptosystem cryptosystem)
{
	this->x = Unumber(s);
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, unsigned base, const Cryptosystem cryptosystem)
{
	this->x = Unumber(s, base);
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, StringType st, const Cryptosystem cryptosystem)
{
	switch (st)
	{
		case Binary: this->x = Unumber(s, Unumber::Binary); break;
		case Decimal: this->x = Unumber(s, Unumber::Decimal); break;
		default: this->x = Unumber(s, Unumber::Decimal); break;
	}

	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, Unumber::StringType st, const Cryptosystem cryptosystem)
{
	switch (st)
	{
		case Unumber::Binary: this->x = Unumber(s, Unumber::Binary); break;
		case Unumber::Decimal: this->x = Unumber(s, Unumber::Decimal); break;
		default: this->x = Unumber(s, Unumber::Decimal); break;
	}

	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(unsigned long long ull, const Cryptosystem cryptosystem)
{
	this->x = Unumber(ull);
	this->cryptosystem = cryptosystem;
}

#endif

