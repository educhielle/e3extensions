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

class SensitiveInformation
{
    /* Private variables */
    private:
	Unumber p, q, phi, phim1;
	Unumber k, km1, g, rndN;
	Unumber p1Nk1N;
	Unumber Nm1;
	Unumber rnd;
	Unumber n, n2;
	
	Unumber twoToBeta;	
	Unumber xp1, xp2;
	Unumber a2, b2;
	unsigned beta, high_bit_posN, high_bit_posN2;

    /* Public variables */
	Unumber sneak;

    /* Constructors */
    public:
	SensitiveInformation() {}
	SensitiveInformation(const string &, const string &, const string &);
	SensitiveInformation(const string &, const string &, const string &, const string &);	
	SensitiveInformation(const Unumber, const Unumber, const Unumber);
	SensitiveInformation(const Unumber, const Unumber, const Unumber, const Unumber);
	SensitiveInformation(unsigned long long, unsigned long long, unsigned long long);
	SensitiveInformation(unsigned long long, unsigned long long, unsigned long long, unsigned long long);

    /* Private functions */
    private:
	Unumber congruence(Unumber x, const Unumber & n);
	void init();
	void next_rnd();
	void setB2Beta(unsigned);

    /* Public functions */
    public:
	Unumber decrypt(Unumber a, Unumber * R);
	Unumber encrypt(Unumber x, Unumber R);
	Unumber encrypt(Unumber x) { return encryptRN(x, random()); }
	Unumber encryptRN(Unumber x, Unumber rN);
        Unumber access_g() const { return g; }
        Unumber access_Nm1() const { return Nm1; }
        Unumber access_p1Nk1N() const { return p1Nk1N; }
        Unumber access_phi() const { return phi; }
        Unumber fkf() const;
	Unumber getBeta() const;
	unsigned getHighBitPosN() const;
	Unumber getN() const;
	Unumber getN2() const;
	Unumber getTwoToBeta() const;
	Unumber getXp1() const;
	Unumber getXp2() const;
	Unumber invertibleRandom() const;
        bool isrnd() const { return !rnd.iszero(); }
	bool leq(const Unumber) const;
        Unumber random() { next_rnd(); return rndN; }
	void setBeta(unsigned);
	Unumber peek_rndN() const { return rndN; }
};

SensitiveInformation::SensitiveInformation(const string & p, const string & q, const string & k)
{
	this->p = Unumber(p);
	this->q = Unumber(q);
	this->k = Unumber(k);
	this->rnd = Unumber(0);

	init();
}

SensitiveInformation::SensitiveInformation(const string & p, const string & q, const string & k, const string & rnd)
{
	this->p = Unumber(p);
	this->q = Unumber(q);
	this->k = Unumber(k);
	this->rnd = Unumber(rnd);

	init();
}

SensitiveInformation::SensitiveInformation(const Unumber p, const Unumber q, const Unumber k)
{
	this->p = p;
	this->q = q;
	this->k = k;
	this->rnd = Unumber(0);

	init();
}

SensitiveInformation::SensitiveInformation(const Unumber p, const Unumber q, const Unumber k, const Unumber rnd)
{
	this->p = p;
	this->q = q;
	this->k = k;
	this->rnd = rnd;

	init();
}

SensitiveInformation::SensitiveInformation(unsigned long long p, unsigned long long q, unsigned long long k)
{
	this->p = Unumber(p);
	this->q = Unumber(q);
	this->k = Unumber(k);
	this->rnd = Unumber(0);

	init();
}

SensitiveInformation::SensitiveInformation(unsigned long long p, unsigned long long q, unsigned long long k, unsigned long long rnd)
{
	this->p = Unumber(p);
	this->q = Unumber(q);
	this->k = Unumber(k);
	this->rnd = Unumber(rnd);

	init();
}

/* Private functions */

Unumber SensitiveInformation::congruence(Unumber x, const Unumber & n)
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

void SensitiveInformation::init()
{
	rndN = 0;
	sneak = 1;

	//implement method similar to init(Unumber n) but calculating n inside the method
	n = p * q; // n = p * q * z;
	n2 = n * n;
	
	/* initialize high_bit_posN and high_bit_posN2 */
	a2 = b2 = high_bit_posN = high_bit_posN2 = 0;

	Unumber x = n - 1;
	while (x != 0) { x >>= 1; high_bit_posN++; }
	high_bit_posN--;

	xp1 = 2;
	xp2 = Unumber(0) - 1;
	xp2 >>= 1;

	x = n2;
	while (x != 0) { x >>= 1; high_bit_posN2++; }
	high_bit_posN2--;

	unsigned nbit = 0;
	while ((n >> ++nbit) != 1);
	a2 = (Unumber(1) << nbit);
	
	/* define xp1 and xp2 for Leq test */
	Unumber tpmax = (Unumber(1) << high_bit_posN) - 1;
	xp1 = n + 1;
	xp2 = n * (tpmax + 1);

	/* what does congruence do? */
	rnd = (rnd.iszero() ? invertibleRandom() : congruence(rnd, n));
	k = congruence(k, n);

	rndN = rnd;
	rndN.pow(n, n2);
	
	phi = (p - 1) * (q - 1);
	// (p - 1) * (q - 1) * (z - 1);

	//skipped is not prime test

	bool ik;

	if (!rnd.iszero())
	{
		ik = ma::invert(rndN, n, &phim1);
		if (!ik) throw "Cannot invert seed: " + rnd.str() + " ^N = " + rndN.str();
	}

	ik = ma::invert(phi, n, &phim1); // inverting by N, not N2
	if ( !ik ) throw "Cannot invert phi";

	ik = ma::invert(k, n, &km1);  // inverting by N, not N2
	if ( !ik ) throw "Cannot invert k";

	g = 1 + k * n;

	ik = ma::invert(n - phi, phi, &Nm1); // inverting N by phi
	if ( !ik ) throw "Cannot invert N";

	p1Nk1N = phim1.mul(km1, n); // modulus is N, not N2

	//skipped - bitguard

	/* Beta */
	Unumber m = n - a2;
	if (m.iszero())
	{
		if (high_bit_posN > 1) setB2Beta(high_bit_posN - 1);
		else {}
	}
	else
	{
		nbit = 0;
		while ((m >> ++nbit) > 1);

		setB2Beta(nbit);

		if (b2 * 2 < a2) {}
		else setB2Beta(nbit - 1);
	}
}

void SensitiveInformation::next_rnd()
{
	if (rndN.iszero()) throw "Rnd used, but not initialised: set random seed";

	//cout << "next_rnd(): rndN = " << rndN.to_ull() << "\tN2 = " << n2.to_ull();
	rndN = rndN.mul(rndN, n2); // for rnd need N, for rndN need N2
	//cout << "\trndN = " << rndN.to_ull() << "\n";
}

void SensitiveInformation::setB2Beta(unsigned b)
{
	beta = b;
	b2 = (Unumber(1) << b);
	twoToBeta = Unumber(2);
	twoToBeta.pow(beta, n2);
	twoToBeta = encrypt(twoToBeta);
}

/* Public functions */

Unumber SensitiveInformation::decrypt(Unumber a, Unumber * R)
{
	Unumber x(fkf());
	Unumber mp1(1);

	//cout << "decrypt: x = " << x.to_ull() << "\ta = " << a.to_ull() << "\t";

	Unumber auxA (a);
	while (x != 0)
	{
		if (x.getbit(0)) mp1 = mp1.mul(auxA, n2);

		auxA = auxA.mul(auxA, n2);
		x >>= 1;
	}
	
	//return mp1;
	Unumber m = mp1 - 1;
	if (m % n != 0) throw "Bad encrypted value " + a.str();
	
	m = m / n;

    	// m is found, now calculate r
    	// first get r^N by r^N*(1+Nkm) * (1-Nkm)
    	// (1-Nkm) = g^(N-m);

	if (!R) return m;

	Unumber r = access_g();

    	r.pow(congruence(n - m, n), n2);
    	r = r.mul(a, n2);
    	r.pow(access_Nm1(), n);
	
    	// verify

    	Unumber rN = r;
    	rN.pow(n, n2);
    	Unumber y = access_g();
    	y.pow(m, n2);
	
    	y = y.mul(rN, n2);
	
    	if (a != y) throw "extract_rm - verification failed for " + a.str();

    	*R = r;
    	return m;
}

Unumber SensitiveInformation::encrypt(Unumber x, Unumber r)
{
	r.pow(n, n2);
	return encryptRN(x, r);
}

Unumber SensitiveInformation::encryptRN(Unumber ix, Unumber rN)
{
	//Unumber rN = random(); // M.random returns r^N, so no powering required
	Unumber gm = access_g();
	gm.pow(congruence(ix, n), n2);
	Unumber x = rN.mul(gm, n2);

	return x;
}

Unumber SensitiveInformation::fkf() const
{
    if ( n2.iszero() ) return n2;
    Unumber Nphi = n.mul(phi, n2);
    Unumber pn = p1Nk1N.mul(sneak, n2);
    return phi.mul(pn, Nphi);
}

unsigned SensitiveInformation::getHighBitPosN() const
{
	return high_bit_posN;
}

Unumber SensitiveInformation::getBeta() const
{
	return beta;
}

Unumber SensitiveInformation::getN() const
{
	return n;
}

Unumber SensitiveInformation::getN2() const
{
	return n2;
}

Unumber SensitiveInformation::getTwoToBeta() const
{
	return twoToBeta;
}

Unumber SensitiveInformation::getXp1() const
{
	return xp1;
}

Unumber SensitiveInformation::getXp2() const
{
	return xp2;
}

/* Invertible Random */
/* Generate an invetible random number */
Unumber SensitiveInformation::invertibleRandom() const
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
bool SensitiveInformation::leq(const Unumber x) const
{
	return ((x < xp1) || (xp2 < x));
}

void SensitiveInformation::setBeta(unsigned b)
{
	if (beta && b > beta)
	{
		std::cout << "Error trying to set beta to " << b << ". Beta cannot be greater than " << beta << ". For greater beta, increase N.\n";
	}
	else
	{
		setB2Beta(b);
	}
}

