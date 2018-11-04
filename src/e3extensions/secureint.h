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
	SecureInt(const Unumber, const Cryptosystem &);
	SecureInt(const string &, const Cryptosystem &);
	SecureInt(const string &, unsigned, const Cryptosystem &);
	SecureInt(const string &, StringType, const Cryptosystem &);
	SecureInt(const string &, Unumber::StringType, const Cryptosystem &);
	SecureInt(long long, Cryptosystem &);

    /* Operators */
    public:
	void operator+= (const SecureInt &);
	void operator+= (unsigned long long);
	void operator-= (const SecureInt &);
	void operator-= (unsigned long long);
	void operator*= (const SecureInt &);
	void operator*= (unsigned long long);
	void operator<<= (const SecureInt &);
	void operator<<= (unsigned);
	void operator>>= (const SecureInt &);
	void operator>>= (unsigned);
	SecureInt operator++ ();
	SecureInt operator-- ();

	friend SecureInt operator+ (const SecureInt & n1) { return n1; }
	friend SecureInt operator- (const SecureInt & n1) { return SecureInt::invert(n1); }

	friend SecureInt operator+ (const SecureInt &, const SecureInt &);
	friend SecureInt operator+ (SecureInt &, unsigned long long);
	friend SecureInt operator+ (unsigned long long, SecureInt &);

	friend SecureInt operator- (const SecureInt &, const SecureInt &);
	friend SecureInt operator- (SecureInt &, unsigned long long);
	friend SecureInt operator- (unsigned long long, SecureInt &);

	friend SecureInt operator* (const SecureInt &, const SecureInt &);
	friend SecureInt operator* (const SecureInt &, unsigned long long);
	friend SecureInt operator* (unsigned long long, const SecureInt &);

	friend SecureInt operator<< (const SecureInt &, const SecureInt &);
	friend SecureInt operator<< (const SecureInt &, unsigned);
	friend SecureInt operator<< (unsigned long long, SecureInt &);

	friend SecureInt operator>> (const SecureInt &, const SecureInt &);
	friend SecureInt operator>> (const SecureInt &, unsigned);
	friend SecureInt operator>> (unsigned long long, SecureInt &);

	friend SecureInt operator== (const SecureInt &, const SecureInt &);
	friend SecureInt operator== (SecureInt &, unsigned long long);
	friend SecureInt operator== (unsigned long long, SecureInt &);

	friend SecureInt operator!= (const SecureInt &, const SecureInt &);
	friend SecureInt operator!= (SecureInt &, unsigned long long);
	friend SecureInt operator!= (unsigned long long, SecureInt &);

	friend SecureInt operator> (const SecureInt &, const SecureInt &);
	friend SecureInt operator> (SecureInt &, unsigned long long);
	friend SecureInt operator> (unsigned long long, SecureInt &);

	friend SecureInt operator< (const SecureInt &, const SecureInt &);
	friend SecureInt operator< (SecureInt &, unsigned long long);
	friend SecureInt operator< (unsigned long long, SecureInt &);

	friend SecureInt operator>= (const SecureInt &, const SecureInt &);
	friend SecureInt operator>= (SecureInt &, unsigned long long);
	friend SecureInt operator>= (unsigned long long, SecureInt &);

	friend SecureInt operator<= (const SecureInt &, const SecureInt &);
	friend SecureInt operator<= (SecureInt &, unsigned long long);
	friend SecureInt operator<= (unsigned long long, SecureInt &);

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
	string str(unsigned base=10) const;

    /* Private static functions */
    public: // changed from private
    static SecureInt pow(const SecureInt &, const SecureInt &, const SecureInt &);
    static SecureInt gcd(const SecureInt &, const SecureInt &);
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
SecureInt::SecureInt(const Unumber x, const Cryptosystem & cryptosystem)
{
	this->x = x;
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, const Cryptosystem & cryptosystem)
{
	this->x = Unumber(s);
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, unsigned base, const Cryptosystem & cryptosystem)
{
	this->x = Unumber(s, base);
	this->cryptosystem = cryptosystem;
}

inline
SecureInt::SecureInt(const string & s, StringType st, const Cryptosystem & cryptosystem)
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
SecureInt::SecureInt(const string & s, Unumber::StringType st, const Cryptosystem & cryptosystem)
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
SecureInt::SecureInt(long long param, Cryptosystem & cryptosystem)
{
	Unumber x;
	if (param < 0)
	{
		x = cryptosystem.encrypt(-param);
		x = cryptosystem.invert(x);
	}
	else x = cryptosystem.encrypt(param);

	this->x = x;
	this->cryptosystem = cryptosystem;
}

#endif
