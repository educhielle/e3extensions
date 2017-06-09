#include <iostream>
#include <istream>
#include "unumberzx.h"

const bool NP_DBG = false;

Unumber Unumber::MOD_VALUE = 0;

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
    if ( st == Decimal ) z = s;
    if ( st == Binary ) throw "GMP binary initialization not implemented";
}

Unumber::Unumber(const string & s, unsigned int base)
{
	if ( base == 10 ) z = s;
	if ( base == 2 ) throw "GMP binary initialization not implemented";
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

// modify here
Unumber Unumber::mul(const Unumber & b, const Unumber & m) const
{

	Unumber r;
/*
	mpz_mul(r.z.get_mpz_t(), z.get_mpz_t(), b.z.get_mpz_t());
	mpz_mod(r.z.get_mpz_t(), r.z.get_mpz_t(), m.z.get_mpz_t());
*/

	if (!mpz_cmp_ui(z.get_mpz_t(), 0) || !mpz_cmp_ui(b.z.get_mpz_t(), 0)) mpz_set_ui(r.z.get_mpz_t(), 0);
	else
	{
		unsigned length = 64;
		size_t *countp;
		unsigned order = 1;
		unsigned endianess = 1;
		unsigned nails = 0;
		unsigned mA[length], mB[length], mC[length], mD[length];

		mpz_export(mA, countp, order, length * sizeof(mA[0]), endianess, nails, z.get_mpz_t());
		mpz_export(mB, countp, order, length * sizeof(mB[0]), endianess, nails, b.z.get_mpz_t());
	
		if (mpz_cmp_ui(m.z.get_mpz_t(), 0)) mpz_export(mC, countp, order, length * sizeof(mC[0]), endianess, nails, m.z.get_mpz_t());
		else for (unsigned i = 0; i < length; i++) mC[i] = 0;

		__asm__ ("moma.mtmr2048 m1(0),%0" : : "r"(mA[63]));
		__asm__ ("moma.mtmr2048 m1(1),%0" : : "r"(mA[62]));
		__asm__ ("moma.mtmr2048 m1(2),%0" : : "r"(mA[61]));
		__asm__ ("moma.mtmr2048 m1(3),%0" : : "r"(mA[60]));
		__asm__ ("moma.mtmr2048 m1(4),%0" : : "r"(mA[59]));
		__asm__ ("moma.mtmr2048 m1(5),%0" : : "r"(mA[58]));
		__asm__ ("moma.mtmr2048 m1(6),%0" : : "r"(mA[57]));
		__asm__ ("moma.mtmr2048 m1(7),%0" : : "r"(mA[56]));
		__asm__ ("moma.mtmr2048 m1(8),%0" : : "r"(mA[55]));
		__asm__ ("moma.mtmr2048 m1(9),%0" : : "r"(mA[54]));
		__asm__ ("moma.mtmr2048 m1(10),%0" : : "r"(mA[53]));
		__asm__ ("moma.mtmr2048 m1(11),%0" : : "r"(mA[52]));
		__asm__ ("moma.mtmr2048 m1(12),%0" : : "r"(mA[51]));
		__asm__ ("moma.mtmr2048 m1(13),%0" : : "r"(mA[50]));
		__asm__ ("moma.mtmr2048 m1(14),%0" : : "r"(mA[49]));
		__asm__ ("moma.mtmr2048 m1(15),%0" : : "r"(mA[48]));
		__asm__ ("moma.mtmr2048 m1(16),%0" : : "r"(mA[47]));
		__asm__ ("moma.mtmr2048 m1(17),%0" : : "r"(mA[46]));
		__asm__ ("moma.mtmr2048 m1(18),%0" : : "r"(mA[45]));
		__asm__ ("moma.mtmr2048 m1(19),%0" : : "r"(mA[44]));
		__asm__ ("moma.mtmr2048 m1(20),%0" : : "r"(mA[43]));
		__asm__ ("moma.mtmr2048 m1(21),%0" : : "r"(mA[42]));
		__asm__ ("moma.mtmr2048 m1(22),%0" : : "r"(mA[41]));
		__asm__ ("moma.mtmr2048 m1(23),%0" : : "r"(mA[40]));
		__asm__ ("moma.mtmr2048 m1(24),%0" : : "r"(mA[39]));
		__asm__ ("moma.mtmr2048 m1(25),%0" : : "r"(mA[38]));
		__asm__ ("moma.mtmr2048 m1(26),%0" : : "r"(mA[37]));
		__asm__ ("moma.mtmr2048 m1(27),%0" : : "r"(mA[36]));
		__asm__ ("moma.mtmr2048 m1(28),%0" : : "r"(mA[35]));
		__asm__ ("moma.mtmr2048 m1(29),%0" : : "r"(mA[34]));
		__asm__ ("moma.mtmr2048 m1(30),%0" : : "r"(mA[33]));
		__asm__ ("moma.mtmr2048 m1(31),%0" : : "r"(mA[32]));
		__asm__ ("moma.mtmr2048 m1(32),%0" : : "r"(mA[31]));
		__asm__ ("moma.mtmr2048 m1(33),%0" : : "r"(mA[30]));
		__asm__ ("moma.mtmr2048 m1(34),%0" : : "r"(mA[29]));
		__asm__ ("moma.mtmr2048 m1(35),%0" : : "r"(mA[28]));
		__asm__ ("moma.mtmr2048 m1(36),%0" : : "r"(mA[27]));
		__asm__ ("moma.mtmr2048 m1(37),%0" : : "r"(mA[26]));
		__asm__ ("moma.mtmr2048 m1(38),%0" : : "r"(mA[25]));
		__asm__ ("moma.mtmr2048 m1(39),%0" : : "r"(mA[24]));
		__asm__ ("moma.mtmr2048 m1(40),%0" : : "r"(mA[23]));
		__asm__ ("moma.mtmr2048 m1(41),%0" : : "r"(mA[22]));
		__asm__ ("moma.mtmr2048 m1(42),%0" : : "r"(mA[21]));
		__asm__ ("moma.mtmr2048 m1(43),%0" : : "r"(mA[20]));
		__asm__ ("moma.mtmr2048 m1(44),%0" : : "r"(mA[19]));
		__asm__ ("moma.mtmr2048 m1(45),%0" : : "r"(mA[18]));
		__asm__ ("moma.mtmr2048 m1(46),%0" : : "r"(mA[17]));
		__asm__ ("moma.mtmr2048 m1(47),%0" : : "r"(mA[16]));
		__asm__ ("moma.mtmr2048 m1(48),%0" : : "r"(mA[15]));
		__asm__ ("moma.mtmr2048 m1(49),%0" : : "r"(mA[14]));
		__asm__ ("moma.mtmr2048 m1(50),%0" : : "r"(mA[13]));
		__asm__ ("moma.mtmr2048 m1(51),%0" : : "r"(mA[12]));
		__asm__ ("moma.mtmr2048 m1(52),%0" : : "r"(mA[11]));
		__asm__ ("moma.mtmr2048 m1(53),%0" : : "r"(mA[10]));
		__asm__ ("moma.mtmr2048 m1(54),%0" : : "r"(mA[9]));
		__asm__ ("moma.mtmr2048 m1(55),%0" : : "r"(mA[8]));
		__asm__ ("moma.mtmr2048 m1(56),%0" : : "r"(mA[7]));
		__asm__ ("moma.mtmr2048 m1(57),%0" : : "r"(mA[6]));
		__asm__ ("moma.mtmr2048 m1(58),%0" : : "r"(mA[5]));
		__asm__ ("moma.mtmr2048 m1(59),%0" : : "r"(mA[4]));
		__asm__ ("moma.mtmr2048 m1(60),%0" : : "r"(mA[3]));
		__asm__ ("moma.mtmr2048 m1(61),%0" : : "r"(mA[2]));
		__asm__ ("moma.mtmr2048 m1(62),%0" : : "r"(mA[1]));
		__asm__ ("moma.mtmr2048 m1(63),%0" : : "r"(mA[0]));

		__asm__ ("moma.mtmr2048 m2(0),%0" : : "r"(mB[63]));
		__asm__ ("moma.mtmr2048 m2(1),%0" : : "r"(mB[62]));
		__asm__ ("moma.mtmr2048 m2(2),%0" : : "r"(mB[61]));
		__asm__ ("moma.mtmr2048 m2(3),%0" : : "r"(mB[60]));
		__asm__ ("moma.mtmr2048 m2(4),%0" : : "r"(mB[59]));
		__asm__ ("moma.mtmr2048 m2(5),%0" : : "r"(mB[58]));
		__asm__ ("moma.mtmr2048 m2(6),%0" : : "r"(mB[57]));
		__asm__ ("moma.mtmr2048 m2(7),%0" : : "r"(mB[56]));
		__asm__ ("moma.mtmr2048 m2(8),%0" : : "r"(mB[55]));
		__asm__ ("moma.mtmr2048 m2(9),%0" : : "r"(mB[54]));
		__asm__ ("moma.mtmr2048 m2(10),%0" : : "r"(mB[53]));
		__asm__ ("moma.mtmr2048 m2(11),%0" : : "r"(mB[52]));
		__asm__ ("moma.mtmr2048 m2(12),%0" : : "r"(mB[51]));
		__asm__ ("moma.mtmr2048 m2(13),%0" : : "r"(mB[50]));
		__asm__ ("moma.mtmr2048 m2(14),%0" : : "r"(mB[49]));
		__asm__ ("moma.mtmr2048 m2(15),%0" : : "r"(mB[48]));
		__asm__ ("moma.mtmr2048 m2(16),%0" : : "r"(mB[47]));
		__asm__ ("moma.mtmr2048 m2(17),%0" : : "r"(mB[46]));
		__asm__ ("moma.mtmr2048 m2(18),%0" : : "r"(mB[45]));
		__asm__ ("moma.mtmr2048 m2(19),%0" : : "r"(mB[44]));
		__asm__ ("moma.mtmr2048 m2(20),%0" : : "r"(mB[43]));
		__asm__ ("moma.mtmr2048 m2(21),%0" : : "r"(mB[42]));
		__asm__ ("moma.mtmr2048 m2(22),%0" : : "r"(mB[41]));
		__asm__ ("moma.mtmr2048 m2(23),%0" : : "r"(mB[40]));
		__asm__ ("moma.mtmr2048 m2(24),%0" : : "r"(mB[39]));
		__asm__ ("moma.mtmr2048 m2(25),%0" : : "r"(mB[38]));
		__asm__ ("moma.mtmr2048 m2(26),%0" : : "r"(mB[37]));
		__asm__ ("moma.mtmr2048 m2(27),%0" : : "r"(mB[36]));
		__asm__ ("moma.mtmr2048 m2(28),%0" : : "r"(mB[35]));
		__asm__ ("moma.mtmr2048 m2(29),%0" : : "r"(mB[34]));
		__asm__ ("moma.mtmr2048 m2(30),%0" : : "r"(mB[33]));
		__asm__ ("moma.mtmr2048 m2(31),%0" : : "r"(mB[32]));
		__asm__ ("moma.mtmr2048 m2(32),%0" : : "r"(mB[31]));
		__asm__ ("moma.mtmr2048 m2(33),%0" : : "r"(mB[30]));
		__asm__ ("moma.mtmr2048 m2(34),%0" : : "r"(mB[29]));
		__asm__ ("moma.mtmr2048 m2(35),%0" : : "r"(mB[28]));
		__asm__ ("moma.mtmr2048 m2(36),%0" : : "r"(mB[27]));
		__asm__ ("moma.mtmr2048 m2(37),%0" : : "r"(mB[26]));
		__asm__ ("moma.mtmr2048 m2(38),%0" : : "r"(mB[25]));
		__asm__ ("moma.mtmr2048 m2(39),%0" : : "r"(mB[24]));
		__asm__ ("moma.mtmr2048 m2(40),%0" : : "r"(mB[23]));
		__asm__ ("moma.mtmr2048 m2(41),%0" : : "r"(mB[22]));
		__asm__ ("moma.mtmr2048 m2(42),%0" : : "r"(mB[21]));
		__asm__ ("moma.mtmr2048 m2(43),%0" : : "r"(mB[20]));
		__asm__ ("moma.mtmr2048 m2(44),%0" : : "r"(mB[19]));
		__asm__ ("moma.mtmr2048 m2(45),%0" : : "r"(mB[18]));
		__asm__ ("moma.mtmr2048 m2(46),%0" : : "r"(mB[17]));
		__asm__ ("moma.mtmr2048 m2(47),%0" : : "r"(mB[16]));
		__asm__ ("moma.mtmr2048 m2(48),%0" : : "r"(mB[15]));
		__asm__ ("moma.mtmr2048 m2(49),%0" : : "r"(mB[14]));
		__asm__ ("moma.mtmr2048 m2(50),%0" : : "r"(mB[13]));
		__asm__ ("moma.mtmr2048 m2(51),%0" : : "r"(mB[12]));
		__asm__ ("moma.mtmr2048 m2(52),%0" : : "r"(mB[11]));
		__asm__ ("moma.mtmr2048 m2(53),%0" : : "r"(mB[10]));
		__asm__ ("moma.mtmr2048 m2(54),%0" : : "r"(mB[9]));
		__asm__ ("moma.mtmr2048 m2(55),%0" : : "r"(mB[8]));
		__asm__ ("moma.mtmr2048 m2(56),%0" : : "r"(mB[7]));
		__asm__ ("moma.mtmr2048 m2(57),%0" : : "r"(mB[6]));
		__asm__ ("moma.mtmr2048 m2(58),%0" : : "r"(mB[5]));
		__asm__ ("moma.mtmr2048 m2(59),%0" : : "r"(mB[4]));
		__asm__ ("moma.mtmr2048 m2(60),%0" : : "r"(mB[3]));
		__asm__ ("moma.mtmr2048 m2(61),%0" : : "r"(mB[2]));
		__asm__ ("moma.mtmr2048 m2(62),%0" : : "r"(mB[1]));
		__asm__ ("moma.mtmr2048 m2(63),%0" : : "r"(mB[0]));

		__asm__ ("moma.mtmr2048 m3(0),%0" : : "r"(mC[63]));
		__asm__ ("moma.mtmr2048 m3(1),%0" : : "r"(mC[62]));
		__asm__ ("moma.mtmr2048 m3(2),%0" : : "r"(mC[61]));
		__asm__ ("moma.mtmr2048 m3(3),%0" : : "r"(mC[60]));
		__asm__ ("moma.mtmr2048 m3(4),%0" : : "r"(mC[59]));
		__asm__ ("moma.mtmr2048 m3(5),%0" : : "r"(mC[58]));
		__asm__ ("moma.mtmr2048 m3(6),%0" : : "r"(mC[57]));
		__asm__ ("moma.mtmr2048 m3(7),%0" : : "r"(mC[56]));
		__asm__ ("moma.mtmr2048 m3(8),%0" : : "r"(mC[55]));
		__asm__ ("moma.mtmr2048 m3(9),%0" : : "r"(mC[54]));
		__asm__ ("moma.mtmr2048 m3(10),%0" : : "r"(mC[53]));
		__asm__ ("moma.mtmr2048 m3(11),%0" : : "r"(mC[52]));
		__asm__ ("moma.mtmr2048 m3(12),%0" : : "r"(mC[51]));
		__asm__ ("moma.mtmr2048 m3(13),%0" : : "r"(mC[50]));
		__asm__ ("moma.mtmr2048 m3(14),%0" : : "r"(mC[49]));
		__asm__ ("moma.mtmr2048 m3(15),%0" : : "r"(mC[48]));
		__asm__ ("moma.mtmr2048 m3(16),%0" : : "r"(mC[47]));
		__asm__ ("moma.mtmr2048 m3(17),%0" : : "r"(mC[46]));
		__asm__ ("moma.mtmr2048 m3(18),%0" : : "r"(mC[45]));
		__asm__ ("moma.mtmr2048 m3(19),%0" : : "r"(mC[44]));
		__asm__ ("moma.mtmr2048 m3(20),%0" : : "r"(mC[43]));
		__asm__ ("moma.mtmr2048 m3(21),%0" : : "r"(mC[42]));
		__asm__ ("moma.mtmr2048 m3(22),%0" : : "r"(mC[41]));
		__asm__ ("moma.mtmr2048 m3(23),%0" : : "r"(mC[40]));
		__asm__ ("moma.mtmr2048 m3(24),%0" : : "r"(mC[39]));
		__asm__ ("moma.mtmr2048 m3(25),%0" : : "r"(mC[38]));
		__asm__ ("moma.mtmr2048 m3(26),%0" : : "r"(mC[37]));
		__asm__ ("moma.mtmr2048 m3(27),%0" : : "r"(mC[36]));
		__asm__ ("moma.mtmr2048 m3(28),%0" : : "r"(mC[35]));
		__asm__ ("moma.mtmr2048 m3(29),%0" : : "r"(mC[34]));
		__asm__ ("moma.mtmr2048 m3(30),%0" : : "r"(mC[33]));
		__asm__ ("moma.mtmr2048 m3(31),%0" : : "r"(mC[32]));
		__asm__ ("moma.mtmr2048 m3(32),%0" : : "r"(mC[31]));
		__asm__ ("moma.mtmr2048 m3(33),%0" : : "r"(mC[30]));
		__asm__ ("moma.mtmr2048 m3(34),%0" : : "r"(mC[29]));
		__asm__ ("moma.mtmr2048 m3(35),%0" : : "r"(mC[28]));
		__asm__ ("moma.mtmr2048 m3(36),%0" : : "r"(mC[27]));
		__asm__ ("moma.mtmr2048 m3(37),%0" : : "r"(mC[26]));
		__asm__ ("moma.mtmr2048 m3(38),%0" : : "r"(mC[25]));
		__asm__ ("moma.mtmr2048 m3(39),%0" : : "r"(mC[24]));
		__asm__ ("moma.mtmr2048 m3(40),%0" : : "r"(mC[23]));
		__asm__ ("moma.mtmr2048 m3(41),%0" : : "r"(mC[22]));
		__asm__ ("moma.mtmr2048 m3(42),%0" : : "r"(mC[21]));
		__asm__ ("moma.mtmr2048 m3(43),%0" : : "r"(mC[20]));
		__asm__ ("moma.mtmr2048 m3(44),%0" : : "r"(mC[19]));
		__asm__ ("moma.mtmr2048 m3(45),%0" : : "r"(mC[18]));
		__asm__ ("moma.mtmr2048 m3(46),%0" : : "r"(mC[17]));
		__asm__ ("moma.mtmr2048 m3(47),%0" : : "r"(mC[16]));
		__asm__ ("moma.mtmr2048 m3(48),%0" : : "r"(mC[15]));
		__asm__ ("moma.mtmr2048 m3(49),%0" : : "r"(mC[14]));
		__asm__ ("moma.mtmr2048 m3(50),%0" : : "r"(mC[13]));
		__asm__ ("moma.mtmr2048 m3(51),%0" : : "r"(mC[12]));
		__asm__ ("moma.mtmr2048 m3(52),%0" : : "r"(mC[11]));
		__asm__ ("moma.mtmr2048 m3(53),%0" : : "r"(mC[10]));
		__asm__ ("moma.mtmr2048 m3(54),%0" : : "r"(mC[9]));
		__asm__ ("moma.mtmr2048 m3(55),%0" : : "r"(mC[8]));
		__asm__ ("moma.mtmr2048 m3(56),%0" : : "r"(mC[7]));
		__asm__ ("moma.mtmr2048 m3(57),%0" : : "r"(mC[6]));
		__asm__ ("moma.mtmr2048 m3(58),%0" : : "r"(mC[5]));
		__asm__ ("moma.mtmr2048 m3(59),%0" : : "r"(mC[4]));
		__asm__ ("moma.mtmr2048 m3(60),%0" : : "r"(mC[3]));
		__asm__ ("moma.mtmr2048 m3(61),%0" : : "r"(mC[2]));
		__asm__ ("moma.mtmr2048 m3(62),%0" : : "r"(mC[1]));
		__asm__ ("moma.mtmr2048 m3(63),%0" : : "r"(mC[0]));

		__asm__ ("moma.modmul2048 m0,m1,m2,m3");

		__asm__ ("moma.mfmr2048 %0,m0(0)" : "=r"(mD[63]));
		__asm__ ("moma.mfmr2048 %0,m0(1)" : "=r"(mD[62]));
		__asm__ ("moma.mfmr2048 %0,m0(2)" : "=r"(mD[61]));
		__asm__ ("moma.mfmr2048 %0,m0(3)" : "=r"(mD[60]));
		__asm__ ("moma.mfmr2048 %0,m0(4)" : "=r"(mD[59]));
		__asm__ ("moma.mfmr2048 %0,m0(5)" : "=r"(mD[58]));
		__asm__ ("moma.mfmr2048 %0,m0(6)" : "=r"(mD[57]));
		__asm__ ("moma.mfmr2048 %0,m0(7)" : "=r"(mD[56]));
		__asm__ ("moma.mfmr2048 %0,m0(8)" : "=r"(mD[55]));
		__asm__ ("moma.mfmr2048 %0,m0(9)" : "=r"(mD[54]));
		__asm__ ("moma.mfmr2048 %0,m0(10)" : "=r"(mD[53]));
		__asm__ ("moma.mfmr2048 %0,m0(11)" : "=r"(mD[52]));
		__asm__ ("moma.mfmr2048 %0,m0(12)" : "=r"(mD[51]));
		__asm__ ("moma.mfmr2048 %0,m0(13)" : "=r"(mD[50]));
		__asm__ ("moma.mfmr2048 %0,m0(14)" : "=r"(mD[49]));
		__asm__ ("moma.mfmr2048 %0,m0(15)" : "=r"(mD[48]));
		__asm__ ("moma.mfmr2048 %0,m0(16)" : "=r"(mD[47]));
		__asm__ ("moma.mfmr2048 %0,m0(17)" : "=r"(mD[46]));
		__asm__ ("moma.mfmr2048 %0,m0(18)" : "=r"(mD[45]));
		__asm__ ("moma.mfmr2048 %0,m0(19)" : "=r"(mD[44]));
		__asm__ ("moma.mfmr2048 %0,m0(20)" : "=r"(mD[43]));
		__asm__ ("moma.mfmr2048 %0,m0(21)" : "=r"(mD[42]));
		__asm__ ("moma.mfmr2048 %0,m0(22)" : "=r"(mD[41]));
		__asm__ ("moma.mfmr2048 %0,m0(23)" : "=r"(mD[40]));
		__asm__ ("moma.mfmr2048 %0,m0(24)" : "=r"(mD[39]));
		__asm__ ("moma.mfmr2048 %0,m0(25)" : "=r"(mD[38]));
		__asm__ ("moma.mfmr2048 %0,m0(26)" : "=r"(mD[37]));
		__asm__ ("moma.mfmr2048 %0,m0(27)" : "=r"(mD[36]));
		__asm__ ("moma.mfmr2048 %0,m0(28)" : "=r"(mD[35]));
		__asm__ ("moma.mfmr2048 %0,m0(29)" : "=r"(mD[34]));
		__asm__ ("moma.mfmr2048 %0,m0(30)" : "=r"(mD[33]));
		__asm__ ("moma.mfmr2048 %0,m0(31)" : "=r"(mD[32]));
		__asm__ ("moma.mfmr2048 %0,m0(32)" : "=r"(mD[31]));
		__asm__ ("moma.mfmr2048 %0,m0(33)" : "=r"(mD[30]));
		__asm__ ("moma.mfmr2048 %0,m0(34)" : "=r"(mD[29]));
		__asm__ ("moma.mfmr2048 %0,m0(35)" : "=r"(mD[28]));
		__asm__ ("moma.mfmr2048 %0,m0(36)" : "=r"(mD[27]));
		__asm__ ("moma.mfmr2048 %0,m0(37)" : "=r"(mD[26]));
		__asm__ ("moma.mfmr2048 %0,m0(38)" : "=r"(mD[25]));
		__asm__ ("moma.mfmr2048 %0,m0(39)" : "=r"(mD[24]));
		__asm__ ("moma.mfmr2048 %0,m0(40)" : "=r"(mD[23]));
		__asm__ ("moma.mfmr2048 %0,m0(41)" : "=r"(mD[22]));
		__asm__ ("moma.mfmr2048 %0,m0(42)" : "=r"(mD[21]));
		__asm__ ("moma.mfmr2048 %0,m0(43)" : "=r"(mD[20]));
		__asm__ ("moma.mfmr2048 %0,m0(44)" : "=r"(mD[19]));
		__asm__ ("moma.mfmr2048 %0,m0(45)" : "=r"(mD[18]));
		__asm__ ("moma.mfmr2048 %0,m0(46)" : "=r"(mD[17]));
		__asm__ ("moma.mfmr2048 %0,m0(47)" : "=r"(mD[16]));
		__asm__ ("moma.mfmr2048 %0,m0(48)" : "=r"(mD[15]));
		__asm__ ("moma.mfmr2048 %0,m0(49)" : "=r"(mD[14]));
		__asm__ ("moma.mfmr2048 %0,m0(50)" : "=r"(mD[13]));
		__asm__ ("moma.mfmr2048 %0,m0(51)" : "=r"(mD[12]));
		__asm__ ("moma.mfmr2048 %0,m0(52)" : "=r"(mD[11]));
		__asm__ ("moma.mfmr2048 %0,m0(53)" : "=r"(mD[10]));
		__asm__ ("moma.mfmr2048 %0,m0(54)" : "=r"(mD[9]));
		__asm__ ("moma.mfmr2048 %0,m0(55)" : "=r"(mD[8]));
		__asm__ ("moma.mfmr2048 %0,m0(56)" : "=r"(mD[7]));
		__asm__ ("moma.mfmr2048 %0,m0(57)" : "=r"(mD[6]));
		__asm__ ("moma.mfmr2048 %0,m0(58)" : "=r"(mD[5]));
		__asm__ ("moma.mfmr2048 %0,m0(59)" : "=r"(mD[4]));
		__asm__ ("moma.mfmr2048 %0,m0(60)" : "=r"(mD[3]));
		__asm__ ("moma.mfmr2048 %0,m0(61)" : "=r"(mD[2]));
		__asm__ ("moma.mfmr2048 %0,m0(62)" : "=r"(mD[1]));
		__asm__ ("moma.mfmr2048 %0,m0(63)" : "=r"(mD[0]));

		mpz_import(r.z.get_mpz_t(), length, order, sizeof(mD[0]), endianess, nails, mD);
	}

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
    mpz_powm(z.get_mpz_t(), z.get_mpz_t(), e.z.get_mpz_t(), mod.z.get_mpz_t());
}
