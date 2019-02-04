#include <iostream>
#include <istream>
#include <fstream>
#include <random>
#include "unumberz_cophee.h"
#include "../cophee/cophee.hpp"

const bool NP_DBG = false;

Unumber Unumber::MOD_VALUE = 0;
int Unumber::pd = 0;

#define ORDER 1
#define ENDIANESS 1
#define NAILS 0

#ifdef ARCH64
	#define WORD_SIZE 64
#else
	#define WORD_SIZE 32
#endif

using namespace std;

inline void Unumber::init_mod_value()
{
    if ( MOD_VALUE == 0 )
    {
        Unumber a(1);
        a <<= MOD_POWER;
        MOD_VALUE = a;
    }
}

void Unumber::neg()
{
    if (z >= 0)
        return;

    if (NP_DBG) std::cout << "CCC " << ("mpz negative [" + str() + "] -> ");
    init_mod_value();

    while (z < 0)
        *this += MOD_VALUE;

    if (NP_DBG) std::cout << ("[" + str() + "]") << '\n';
}

void Unumber::pos()
{
    init_mod_value();

    if (z < MOD_VALUE.z)
        return;

    if (NP_DBG) std::cout << "CCC " << ("mpz positive [" + str() + "] -> ");

    while (z >= MOD_VALUE.z)
        *this -= MOD_VALUE;

    if (NP_DBG) std::cout << ("[" + str() + "]") << '\n';
}

Unumber::Unumber(unsigned long long x): z((unsigned long)(x)) {}
Unumber::Unumber(): z(0) {}

void Unumber::operator*=(const Unumber & n) { z *= n.z; }
void Unumber::operator+=(const Unumber & n) { z += n.z; pos(); }
void Unumber::operator-=(const Unumber & n) { z -= n.z; neg(); }
void Unumber::operator%=(const Unumber & n) { z %= n.z; }
void Unumber::operator/=(const Unumber & n) { z /= n.z; }

Unumber & Unumber::operator++() { z += 1; return *this; }
Unumber & Unumber::operator--() { z -= 1; return *this; }

bool Unumber::iszero() const { return z == 0; }

string Unumber::str(unsigned base) const { return z.get_str(base); }

unsigned long long Unumber::to_ull() const { return z.get_ui(); }

void Unumber::operator<<=(int b) { mpz_mul_2exp (z.get_mpz_t(), z.get_mpz_t(), b); }
void Unumber::operator>>=(int b) { mpz_div_2exp (z.get_mpz_t(), z.get_mpz_t(), b); }

bool operator<(const Unumber & n1, const Unumber & n2) { return n1.z < n2.z; }

Unumber::Unumber(const string & s, Unumber::StringType st)
{
/*
    if ( st == Decimal ) z = s;
    if ( st == Binary ) throw "GMP binary initialization not implemented";
*/
	unsigned int base = 0;
	switch ( st )
	{
		case Decimal: base = 10; break;
		case Binary: base = 2; break;
		case Hexadecimal: base = 16; break;
	}
	mpz_set_str(z.get_mpz_t(), s.c_str(), base);
}

Unumber::Unumber(const string & s, unsigned int base)
{
	mpz_set_str(z.get_mpz_t(), s.c_str(), base);
/*	if ( base == 10 ) z = s;
	if ( base == 2 ) throw "GMP binary initialization not implemented";
*/
}

Unumber::Unumber(const Unumber & n)
{
	z = n.str();
}

Unumber Unumber::div(const Unumber & d, Unumber & q) const
{
    Unumber r;
    mpz_fdiv_qr (q.z.get_mpz_t(), r.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());
    return r;
}

void Unumber::divABRQ(const Unumber & d, Unumber * r, Unumber * q) const
{
    Unumber m;

    if (q)
        mpz_fdiv_qr (q->z.get_mpz_t(), m.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());
    else
        mpz_fdiv_r (m.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());

    if (r) *r = m;
}

Unumber Unumber::mul(const Unumber & b, const Unumber & m) const
{
    Unumber r;
#if COPHEE == 2
	r = Unumber::hw_modmul(*this, b);
#else
	// std::cout << "m " << std::flush;
    mpz_mul(r.z.get_mpz_t(), z.get_mpz_t(), b.z.get_mpz_t());
    mpz_mod(r.z.get_mpz_t(), r.z.get_mpz_t(), m.z.get_mpz_t());
#endif
    return r;
}

unsigned Unumber::Unumber::getbit(int b) const { return mpz_tstbit(z.get_mpz_t(), b); }

void Unumber::setbit1(int b)
{
    if (b)
        mpz_setbit(z.get_mpz_t(), b);
    else
        mpz_clrbit(z.get_mpz_t(), b);
}


std::istream & operator>>(std::istream & is, Unumber & n)
{
    std::string s; is >> s;

    if(!s.empty() && !!is )
    {
        Unumber u(s, Unumber::Decimal);
        n.swap(u);
    }

    return is;
}

void Unumber::pow(Unumber e, const Unumber & mod)
{
#if COPHEE == 2
	(*this) = Unumber::hw_modexp(*this, e);
#else
	// std::cout << "e " << std::flush;
    mpz_powm(z.get_mpz_t(), z.get_mpz_t(), e.z.get_mpz_t(), mod.z.get_mpz_t());
#endif
}

void Unumber::exportArray(unsigned arr[], unsigned length, Unumber u)
{
	size_t *countp;
	unsigned size = length * sizeof(unsigned);
	if (mpz_cmp_ui(u.z.get_mpz_t(), 0)) mpz_export(arr, countp, ORDER, size, ENDIANESS, NAILS, u.z.get_mpz_t());
	else for (unsigned i = 0; i < length; i++) arr[i] = 0;
}

Unumber Unumber::importArray(unsigned arr[], unsigned length)
{
	Unumber r;
	mpz_import(r.z.get_mpz_t(), length, ORDER, sizeof(unsigned), ENDIANESS, NAILS, arr);
	return r;
}

Unumber Unumber::gmpmul(const Unumber & a, const Unumber & b)
{
    Unumber r;
    mpz_mul(r.z.get_mpz_t(), a.z.get_mpz_t(), b.z.get_mpz_t());
    return r;
}

void Unumber::initCophee()
{
    ifstream in;
	in.open("CS.txt", ifstream::in);
	stringstream buffer;
	buffer << in.rdbuf();
	string text = buffer.str();
	in.close();

	int len = 11;
	int semicolon[len];
	semicolon[0] = text.find(";") + 1;
	for (int i = 1; i < len; i++)
	{
		semicolon[i] = text.find(";", semicolon[i-1]) + 1;
	}
	//int newLine = text.find("\n") + 1;
	//string strP   = text.substr(semicolon[0], semicolon[1]-semicolon[0]-1);
	//string strQ   = text.substr(semicolon[1], semicolon[2]-semicolon[1]-1);
	//string strK   = text.substr(semicolon[2], semicolon[3]-semicolon[2]-1);
	//string strBeta	= text.substr(semicolon[3], semicolon[4]-semicolon[3]-1);
	string strFKF = text.substr(semicolon[4], semicolon[5]-semicolon[4]-1);
	// string strG   = text.substr(semicolon[5], semicolon[6]-semicolon[5]-1);
	string strN   = text.substr(semicolon[6], semicolon[7]-semicolon[6]-1);
	// string strXp1 = text.substr(semicolon[7], semicolon[8]-semicolon[7]-1);
	// string strXp2 = text.substr(semicolon[8], semicolon[9]-semicolon[8]-1);

	//cout << text << "\n";

	//p = Unumber(strP);
	//q = Unumber(strQ);
	//k = Unumber(strK);
	Unumber fkf = Unumber(strFKF);
	// Unumber _g = Unumber(strG);
	Unumber n = Unumber(strN);
	// xp1 = Unumber(strXp1);
	// xp2 = Unumber(strXp2);
	Unumber n2 = Unumber::gmpmul(n, n);
    Unumber rand0 = invertibleRandom(n);
    Unumber rand1 = invertibleRandom(n);
    Unumber::exportArray(cleq_N, 32, n);
    Unumber::exportArray(cleq_NSQ, 64, n);
    Unumber::exportArray(cleq_fkf, 64, fkf);
    Unumber::exportArray(cleq_rand0, 32, rand0);
    Unumber::exportArray(cleq_rand1, 32, rand1);
    Unumber::pd = init_port() ;
	// initArduino();
	Unumber::resetCounters();
    initialize_chip (Unumber::pd) ;
}

Unumber Unumber::invertibleRandom(const Unumber & n)
{
    unsigned high_bit_posN = 0;
    Unumber x = n - 1;
    while (x != 0) { x >>= 1; high_bit_posN++; }
    high_bit_posN--;

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
         mpz_t mgcd;
         mpz_init(mgcd);
        mpz_gcd(mgcd, number.z.get_mpz_t(), n.z.get_mpz_t());
        unsigned ugcd = mpz_get_ui(mgcd);
		if ((number < n) && (ugcd == 1)) break;

        // if ((number < n) && (ma::gcd(number, n) == 1)) break;
	}

	return number;
}

void Unumber::resetCounters()
{
    timeRead = 0; countRead = 0;
    timeWrite = 0; countWrite = 0;
    timeMul = 0; countMul = 0;
    timeExp = 0; countExp = 0;
    timeInv = 0; countInv = 0;
    timeGfun = 0; countGfun = 0;
}

// unsigned long long Unumber::getTimeSerial() { return timeSerial; }
// unsigned long long Unumber::getTimeMul() { return timeMul; }
// unsigned long long Unumber::getTimeExp() { return timeExp; }
// unsigned long long Unumber::getTimeInv() { return timeInv; }
// unsigned long long Unumber::getTimeGfun() { return timeGfun; }

void Unumber::showTimes()
{
    cout << "Read : " << timeRead  << " ( count: " << countRead  << " ) [ avg: " << (double(timeRead )/countRead ) << " ]\n";
    cout << "Write: " << timeWrite << " ( count: " << countWrite << " ) [ avg: " << (double(timeWrite)/countWrite) << " ]\n";
    cout << "Mul  : " << timeMul   << " ( count: " << countMul   << " ) [ avg: " << (double(timeMul  )/countMul  ) << " ]\n";
    cout << "Exp  : " << timeExp   << " ( count: " << countExp   << " ) [ avg: " << (double(timeExp  )/countExp  ) << " ]\n";
    cout << "Inv  : " << timeInv   << " ( count: " << countInv   << " ) [ avg: " << (double(timeInv  )/countInv  ) << " ]\n";
    cout << "Gfun : " << timeGfun  << " ( count: " << countGfun  << " ) [ avg: " << (double(timeGfun )/countGfun ) << " ]\n";
}

Unumber Unumber::hw_modmul(const Unumber & x, const Unumber & y)
{
#if COPHEE == 2
    std::cout << "m " << std::flush;
    unsigned vx[LENGTH], vy[LENGTH];
    Unumber::exportArray(vx, LENGTH, x);
    Unumber::exportArray(vy, LENGTH, y);
    auto vr = mod_mul(vx, vy, Unumber::pd);
    return Unumber::importArray(vr, LENGTH);
#else
    std::cout << "m! " << std::flush;
    return x;
#endif
}

Unumber Unumber::hw_modexp(const Unumber & x, const Unumber & y)
{
#if COPHEE == 2
std::cout << "e " << std::flush;
unsigned vx[LENGTH], vy[LENGTH];
Unumber::exportArray(vx, LENGTH, x);
Unumber::exportArray(vy, LENGTH, y);
auto vr = mod_exp(vx, vy, Unumber::pd);
return Unumber::importArray(vr, LENGTH);
#else
    std::cout << "e! " << std::flush;
    return x;
#endif
}

Unumber Unumber::hw_gcd(const Unumber & x, const Unumber & y)
{
#if COPHEE == 2
    std::cout << "g " << std::flush;
    unsigned vx[LENGTH], vy[LENGTH];
    Unumber::exportArray(vx, LENGTH, x);
    Unumber::exportArray(vy, LENGTH, y);
    auto vr = mod_inv(vx, vy, Unumber::pd);
    if (vr == 0) return Unumber(0);
    return Unumber::importArray(vr, LENGTH);
#else
    std::cout << "g! " << std::flush;
    return x;
#endif
}

Unumber Unumber::hw_inv(const Unumber & x, const Unumber & y)
{
#if COPHEE == 2
    std::cout << "i " << std::flush;
    unsigned vx[LENGTH], vy[LENGTH];
    Unumber::exportArray(vx, LENGTH, x);
    Unumber::exportArray(vy, LENGTH, y);
    auto vr = mod_inv(vx, vy, Unumber::pd);
    return Unumber::importArray(vr, LENGTH);
#else
    std::cout << "i! " << std::flush;
    return x;
#endif
}

Unumber Unumber::hw_gfun(const Unumber & x, const Unumber & y)
{
#ifdef COPHEE
    std::cout << "G " << std::flush;
    unsigned vx[LENGTH], vy[LENGTH];
    Unumber::exportArray(vx, LENGTH, x);
    Unumber::exportArray(vy, LENGTH, y);
    auto vr = gfunc(vx, vy, Unumber::pd);
    return Unumber::importArray(vr, LENGTH);
#else
    std::cout << "G! " << std::flush;
    return x;
#endif
}
