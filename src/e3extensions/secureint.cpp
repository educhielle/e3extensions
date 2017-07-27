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
/* Equivalent to a modular multiplication */
void SecureInt::operator+= (const SecureInt & param)
{
	x = x.mul(param.x, cryptosystem.getN2());
}

void SecureInt::operator+= (unsigned long long param)
{
	Unumber y = cryptosystem.encrypt(Unumber(param));
	x = x.mul(y, cryptosystem.getN2());
}

/* Encrypted subtraction */
/* Equivalent to a modular multiplication of the minuend with the inverse of the subtrahend */
void SecureInt::operator-= (const SecureInt & param)
{
	*this += SecureInt::invert(param);
}

void SecureInt::operator-= (unsigned long long param)
{
	Unumber y = cryptosystem.encrypt(Unumber(-param));
	x = x.mul(y, cryptosystem.getN2());
}

/* Encrypted multiplication */
void SecureInt::operator*= (const SecureInt& param)
{
	SecureInt y (param), z, bit;

	// sum = ~0
	Unumber uzero = cryptosystem.getZero();
	SecureInt sum(uzero, cryptosystem);

	// Beta+1 times
	unsigned betap1 = cryptosystem.getBeta() + 2;

	// for (B+1) times do
	while (--betap1 > 0)
	{
		// z = Div2(x)
		z = (*this).div2();

		// bit = x - (z + z)
		bit = *this - (z + z);

		// sum = sum + G(bit,y)
		sum = sum + SecureInt::G(bit,y);

		// y = y + y
		y = y + y;

		// x = z
		*this = z;
	}
	
	*this = sum;
}

void SecureInt::operator*= (unsigned long long param)
{
	SecureInt y (cryptosystem.encrypt(Unumber(param)), cryptosystem);
	*this *= y;
}

/* Shift left */
/* Multiply number by a power of two */
void SecureInt::operator<<= (const SecureInt& param)
{
	SecureInt s (param);
	unsigned beta = cryptosystem.getBeta();
	while (beta-- > 0)
	{
		*this = *this + SecureInt::G(s, *this);
		--s;
	}
}

void SecureInt::operator<<= (unsigned shift)
{
	for (unsigned i = 0; i < shift; i++) *this += *this;
}

/* Shift right */
/* Divide number by a power of two */
void SecureInt::operator>>= (const SecureInt& param)
{
	SecureInt s (param);
	Unumber uone = cryptosystem.getOne();
	SecureInt one (uone, cryptosystem);
	unsigned beta = cryptosystem.getBeta();
	while (beta-- > 0)
	{
		SecureInt d2 (*this);
		*this = SecureInt::G(s, d2.div2()) + SecureInt::G(one-s, *this);
		--s;
	}
}

void SecureInt::operator>>= (unsigned shift)
{
	for (unsigned i = 0; i < shift; i++) *this = div2();
}

/* Encrypted increment */
/* Equivalent to a modular multiplication */
void SecureInt::operator++ ()
{
	x = x.mul(cryptosystem.getOne(), cryptosystem.getN2());
}

/* Encrypted decrement */
/* Equivalent to a inverse followed by modular multiplication */
void SecureInt::operator-- ()
{
	x = x.mul(cryptosystem.invert(cryptosystem.getOne()), cryptosystem.getN2());
}


/* Equal */
/* Compare if two encrypted numbers are equal */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Equal(x,y) = ~1 - ( G(x-y,~1) + G(y-x,~1) ) */
SecureInt operator== (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt equal = one - (SecureInt::G(n1-n2,one) + SecureInt::G(n2-n1,one));
	return equal;
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Different(x,y) = G(x-y,~1) + G(y-x,~1) */
SecureInt operator!= (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt r = SecureInt::G(n1-n2,one) + SecureInt::G(n2-n1,one);
	return r;
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Different(x,y) = G(x-y,~1) + G(y-x,~1) */
SecureInt operator> (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt r = SecureInt::G(n1-n2,one);
	return r;
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Different(x,y) = G(x-y,~1) + G(y-x,~1) */
SecureInt operator< (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt r = SecureInt::G(n2-n1,one);
	return r;
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Different(x,y) = G(x-y,~1) + G(y-x,~1) */
SecureInt operator>= (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt r = one - SecureInt::G(n2-n1,one);
	return r;
}

/* Different */
/* Compare if two encrypted numbers are different */
/* Return encrypted one if true, and encrypted zero otherwise */
/* Different(x,y) = G(x-y,~1) + G(y-x,~1) */
SecureInt operator<= (const SecureInt & n1, const SecureInt & n2)
{
	//Cryptosystem cs(n1.cryptosystem);
	//Unumber uone = cs.getOne();
	Unumber uone = n1.cryptosystem.getOne();
	SecureInt one (uone,n1.cryptosystem);
	SecureInt r = one - SecureInt::G(n1-n2,one);
	return r;
}


/************************************
 *     PRIVATE OBJECT FUNCTIONS     *
 ************************************/

/* Return an encrypted number that is half of the object's value */
SecureInt SecureInt::div2()
{
	// sum = ~0
	Unumber uzero = cryptosystem.getZero();
	SecureInt sum(uzero, cryptosystem);

	// p2 = ~2^B
	//Unumber twoToBeta = cryptosystem.getTwoToBeta();
	SecureInt p2;// (twoToBeta, cryptosystem);

	// Other SecureInt variables
	Unumber uone = cryptosystem.getOne();
	SecureInt one (uone, cryptosystem);
	SecureInt y;

	// Beta
	//Unumber beta = cryptosystem.getBeta() + 1;
	unsigned beta = cryptosystem.getBeta();
	
	// for Beta times do
	while (beta-- > 0)
	{
		// p2 = Half(p2)
		//p2 = p2.half2();
		p2 = SecureInt(cryptosystem.getPowerOfTwo(beta), cryptosystem);		

		// y = sum + p2
		y = sum + p2;

		// y = y + y - x
		y = y + y - *this;

		// sum = sum + G(~1-y,p2)
		sum = sum + G(one-y,p2);
	}
	
	return sum;
}

/* Return the half of an encrypted number that is power of two */
SecureInt SecureInt::half2()
{
	// sum = ~0
	Unumber uzero = cryptosystem.getZero();
	SecureInt sum (uzero, cryptosystem);

	// p2 = ~1
	Unumber uone = cryptosystem.getOne();
	SecureInt p2 (uone, cryptosystem);

	// Other SecureInt variables
	SecureInt one (uone, cryptosystem);
	SecureInt zero (uzero, cryptosystem);
	SecureInt y, my;
	
	// Beta times
	unsigned beta = cryptosystem.getBeta() + 1;
	
	while (--beta > 0)
	{
		// y = p2 + p2 - x
		y = p2 + p2 - *this;

		// |y| = G(y,y)+G(-y,-y)
		my = -y;
		y = G(y,y) + G(my,my);

		// y = G(|y|,~1)
		y = G(y,one);

		// y = G(~1-y,p2)
		y = G(one-y,p2);

		// sum = sum + y
		sum = sum + y;

		// p2 = p2 + p2
		p2 = p2 + p2;
	}
	
	return sum;
}


/***********************************
 *     PUBLIC OBJECT FUNCTIONS     *
 ***********************************/

/* G function */
SecureInt SecureInt::g(const SecureInt & param) const
{
	return SecureInt::G(*this,param);
}

/* Return the Cryptosystem */
Cryptosystem SecureInt::getCryptosystem() const
{
	return cryptosystem;
}

/* Return N */
Unumber SecureInt::getN() const
{
	return cryptosystem.getN();
}

/* Return N^2 */
Unumber SecureInt::getN2() const
{
	return cryptosystem.getN2();
}

/* Return the cyphertext (x) */
Unumber SecureInt::getX() const
{
	return x;
}

/* Return the inverse of a number */
SecureInt SecureInt::invert() const
{
	return SecureInt::invert(*this);
}

/* Return the cyphertext in string format */
string SecureInt::str(unsigned base) const
{
	return x.str(base);
}


/************************************
 *     PRIVATE STATIC FUNCTIONS     *
 ************************************/

/* Return the inverse of a number */
SecureInt SecureInt::invert(const SecureInt & param)
{
	Unumber inv = param.cryptosystem.invert(param.x);
	/*
	bool k = ma::invert(param.x, param.cryptosystem.getN2(), &inv);
	if ( !k )
	{
		std::cout << "SecureInt: inverse does not exist.\n";
		throw "Inverse does not exist.\n";
	}
	*/

	return SecureInt(inv, param.cryptosystem);
}


/***********************************
 *     PUBLIC STATIC FUNCTIONS     *
 ***********************************/

/* G function */
SecureInt SecureInt::g(const SecureInt & n1, const SecureInt & n2)
{
	return SecureInt::G(n1,n2);
}

/* G function */
SecureInt SecureInt::G(const SecureInt & n1, const SecureInt & n2)
{
	Unumber gres = n1.cryptosystem.g(n1.x, n2.x);
	return SecureInt(gres, n1.cryptosystem);
}

