#include <iostream>

#include "unumberg.h"

#include "meuclid.h"
#include "ma_invert_m.h"

struct UnumberContractor
{
    typedef UnumberContractor UC;

    Unumber x;
    UnumberContractor() {}
    UnumberContractor(const Unumber & a) : x(a) {}
    UnumberContractor(unsigned long long a) : x(a) {}

    // Constrains
    bool operator==(const UC & a) const { return x == a.x; }
    void mulMod(const UC & b, const UC & mod) { x = x.mul(b.x, mod.x); }
    bool operator<(const UC & a) const { return x < a.x; }
    void swap(UC & a) { x.swap(a.x); }
    void add(const UC & b) { x += b.x; }
    void sub(const UC & b) { x -= b.x; }
    std::string str() const { return x.str(); }

    static void divABRQ(const UC & a, const UC & b, UC * r, UC * q)
    { a.x.divABRQ(b.x, r ? &r->x : 0, q ? &q->x : 0); }

    // Derived
    bool operator!=(const UC & a) const { return !(*this == a); }
    void subMod(const UC & b, const UC & mod) { if ( *this < b) add(mod); sub(b); }
    void addMod(const UC & b, const UC & mod)
    {
        add(b);
            while (1) if ( *this < mod ) break; else sub(mod);
    }
    bool operator>(const UC & a) const { return !(*this < a || *this == a); }


};

typedef UnumberContractor UC;

// instanciate Euclid class with the adapter
//template class Meuclid<UC>;

bool ma::invert(const Unumber & x, const Unumber & mod, Unumber * xm1)
{
#ifndef HWACC
    UC ucx(x);
    UC ucmod(mod);

    Invertor<UC> iuc(ucx, ucmod);

    if ( !iuc.isOk() ) return false;

    if (xm1) *xm1 = iuc.get().x;

    return true;
#else
	mpz_t mpz_x, mpz_y, mpz_r;
	mpz_init(mpz_x);
	mpz_init(mpz_y);
	mpz_init(mpz_r);
	mpz_set_str(mpz_x, x.str().c_str(), 10);
	mpz_set_str(mpz_y, mod.str().c_str(), 10);

	unsigned length = 64;
	size_t *countp;
	unsigned order = 1;
	unsigned endianess = 1;
	unsigned nails = 0;
	unsigned mA[length], mB[length], mD[length];
	unsigned size = length * sizeof(unsigned);

	if (mpz_cmp_ui(mpz_x, 0)) mpz_export(mA, countp, order, size, endianess, nails, mpz_x);
	else for (unsigned i = 0; i < length; i++) mA[i] = 0;

	if (mpz_cmp_ui(mpz_y, 0)) mpz_export(mB, countp, order, size, endianess, nails, mpz_y);
	else for (unsigned i = 0; i < length; i++) mB[i] = 0;

	Unumber::mtmr2048_m1(mA);
	Unumber::mtmr2048_m2(mB);

	__asm__ ("moma.inv2048 m0,m1,m2");

	Unumber::mfmr2048_m0(mD);

	mpz_import(mpz_r, length, order, sizeof(unsigned), endianess, nails, mD);

	*xm1 = Unumber (mpz_get_str(NULL, 10, mpz_r));
	return true;
#endif
}

Unumber ma::gcd(const Unumber & x, const Unumber & y)
{
#ifndef HWACC
    UC ucx(x);
    UC ucy(y);

    Meuclid<UC> iuc(ucx, ucy, ucy);

    return iuc.gcd().x;
#else
	mpz_t mpz_x, mpz_y, mpz_r;
	mpz_init(mpz_x);
	mpz_init(mpz_y);
	mpz_init(mpz_r);
	mpz_set_str(mpz_x, x.str().c_str(), 10);
	mpz_set_str(mpz_y, y.str().c_str(), 10);

	unsigned length = 64;
	size_t *countp;
	unsigned order = 1;
	unsigned endianess = 1;
	unsigned nails = 0;
	unsigned mA[length], mB[length], mD[length];
	unsigned size = length * sizeof(unsigned);

	if (mpz_cmp_ui(mpz_x, 0)) mpz_export(mA, countp, order, size, endianess, nails, mpz_x);
	else for (unsigned i = 0; i < length; i++) mA[i] = 0;

	if (mpz_cmp_ui(mpz_y, 0)) mpz_export(mB, countp, order, size, endianess, nails, mpz_y);
	else for (unsigned i = 0; i < length; i++) mB[i] = 0;

	Unumber::mtmr2048_m1(mA);
	Unumber::mtmr2048_m2(mB);

	__asm__ ("moma.gcd2048 m0,m1,m2");

	Unumber::mfmr2048_m0(mD);

	mpz_import(mpz_r, length, order, sizeof(unsigned), endianess, nails, mD);

	Unumber r (mpz_get_str(NULL, 10, mpz_r));
	return r;
#endif
}

#include "meuclid.inc"
