#include <iostream>
#include <istream>
#include "unumberzx.h"
#include "unumberzx2048asm.h"

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

void Unumber::operator*=(const Unumber & n) { z *= n.z; /*stats_operatorMul++;*/ }
void Unumber::operator+=(const Unumber & n) { z += n.z; pos(); /*stats_operatorAdd++;*/ }
void Unumber::operator-=(const Unumber & n) { z -= n.z; neg(); /*stats_operatorSub++;*/ }
void Unumber::operator%=(const Unumber & n) { z %= n.z;/* stats_operatorMod++;*/ }
void Unumber::operator/=(const Unumber & n) { z /= n.z; /*stats_operatorDiv++;*/ }

Unumber & Unumber::operator++() { /*stats_operatorInc++;*/ z += 1; return *this; }
Unumber & Unumber::operator--() {/* stats_operatorDec++;*/ z -= 1; return *this; }

bool Unumber::iszero() const { /*stats_iszero++;*/ return z == 0; }

string Unumber::str(unsigned base) const { return z.get_str(base); }

unsigned long long Unumber::to_ull() const { return z.get_ui(); }

void Unumber::operator<<=(int b) { mpz_mul_2exp (z.get_mpz_t(), z.get_mpz_t(), b); /*stats_operatorShiftLeft++;*/ }
void Unumber::operator>>=(int b) { mpz_div_2exp (z.get_mpz_t(), z.get_mpz_t(), b); /*stats_operatorShiftRight++;*/ }

bool operator<(const Unumber & n1, const Unumber & n2) { /*stats_operatorLess++;*/ return n1.z < n2.z; }
bool operator==(const Unumber & n1, const Unumber & n2) { /*stats_operatorEqual++;*/ return n1.z == n2.z; }

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
/*stats_div++;*/
    Unumber r;
    mpz_fdiv_qr (q.z.get_mpz_t(), r.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());
    return r;
}

void Unumber::divABRQ(const Unumber & d, Unumber * r, Unumber * q) const
{
/*stats_divABRQ++;*/
    Unumber m;

    if (q)
        mpz_fdiv_qr (q->z.get_mpz_t(), m.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());
    else
        mpz_fdiv_r (m.z.get_mpz_t(), z.get_mpz_t(), d.z.get_mpz_t());

    if (r) *r = m;
}

Unumber Unumber::mul(const Unumber & b, const Unumber & m) const
{
/*stats_mul++;*/
//std::cout << "mul\n";
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
		unsigned size = length * sizeof(unsigned);

		mpz_export(mA, countp, order, size, endianess, nails, z.get_mpz_t());
		mpz_export(mB, countp, order, size, endianess, nails, b.z.get_mpz_t());
	
		if (mpz_cmp_ui(m.z.get_mpz_t(), 0)) mpz_export(mC, countp, order, size, endianess, nails, m.z.get_mpz_t());
		else for (unsigned i = 0; i < length; i++) mC[i] = 0;

		mter_ye1(mA);
		mter_ye2(mB);
		mter_ye3(mC);

		__asm__ ("le3.modmul ye0,ye1,ye2,ye3");

		mfer_ye0(mD);

		mpz_import(r.z.get_mpz_t(), length, order, sizeof(unsigned), endianess, nails, mD);
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
/*stats_pow++;*/
//std::cout << "pow\n";
//	mpz_powm(z.get_mpz_t(), z.get_mpz_t(), e.z.get_mpz_t(), mod.z.get_mpz_t());

	unsigned length = 64;
	size_t *countp;
	unsigned order = 1;
	unsigned endianess = 1;
	unsigned nails = 0;
	unsigned mA[length], mB[length], mC[length], mD[length];
	unsigned size = length * sizeof(unsigned);

	if (mpz_cmp_ui(z.get_mpz_t(), 0)) mpz_export(mA, countp, order, size, endianess, nails, z.get_mpz_t());
	else for (unsigned i = 0; i < length; i++) mA[i] = 0;

	if (mpz_cmp_ui(e.z.get_mpz_t(), 0)) mpz_export(mB, countp, order, size, endianess, nails, e.z.get_mpz_t());
	else for (unsigned i = 0; i < length; i++) mB[i] = 0;

	if (mpz_cmp_ui(mod.z.get_mpz_t(), 0)) mpz_export(mC, countp, order, size, endianess, nails, mod.z.get_mpz_t());
	else for (unsigned i = 0; i < length; i++) mC[i] = 0;

	mter_ye1(mA);
	mter_ye2(mB);
	mter_ye3(mC);

	__asm__ ("le3.modexp ye0,ye1,ye2,ye3");

	mfer_ye0(mD);

	mpz_import(z.get_mpz_t(), length, order, sizeof(unsigned), endianess, nails, mD);
}

void Unumber::swap(Unumber & n) { /*stats_swap++;*/ mpz_class t = z; z=n.z; n.z=t; }

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

/*
void Unumber::prita()
{
	std::cout << "---\n";
	
	std::cout << "stats_operatorAdd: " << stats_operatorAdd << "\n";
	std::cout << "stats_operatorSub: " << stats_operatorSub << "\n";
	std::cout << "stats_operatorMul: " << stats_operatorMul << "\n";
	std::cout << "stats_operatorDiv: " << stats_operatorDiv << "\n";
	std::cout << "stats_operatorMod: " << stats_operatorMod << "\n";
	std::cout << "stats_operatorShiftLeft: " << stats_operatorShiftLeft << "\n";
	std::cout << "stats_operatorShiftRight: " << stats_operatorShiftRight << "\n";
	std::cout << "stats_operatorLess: " << stats_operatorLess << "\n";
	std::cout << "stats_operatorGreater: " << stats_operatorGreater << "\n";
	std::cout << "stats_operatorEqual: " << stats_operatorEqual << "\n";
	std::cout << "stats_operatorInc: " << stats_operatorInc << "\n";
	std::cout << "stats_operatorDec: " << stats_operatorDec << "\n";
	std::cout << "stats_iszero: " << stats_iszero << "\n";
	std::cout << "stats_swap: " << stats_swap << "\n";
	std::cout << "stats_div: " << stats_div << "\n";
	std::cout << "stats_divABRQ: " << stats_divABRQ << "\n";
	std::cout << "stats_mul: " << stats_mul << "\n";
	std::cout << "stats_pow: " << stats_pow << "\n";

	std::cout << "---\n";
}
*/
