//#include <iostream>

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
//std::cout << "ma::invert\n";
	unsigned length = 64;
	unsigned mA[length], mB[length], mD[length];

	Unumber::exportArray(mA, length, x);
	Unumber::exportArray(mB, length, mod);

	Unumber::mter_ye1(mA);
	Unumber::mter_ye2(mB);

	__asm__ ("le3.inv ye0,ye1,ye2");

	Unumber::mfer_ye0(mD);

	*xm1 = Unumber::importArray(mD, length);
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
//std::cout << "ma::gcd\n";
	unsigned length = 64;
	unsigned mA[length], mB[length], mD[length];

	Unumber::exportArray(mA, length, x);
	Unumber::exportArray(mB, length, y);

	Unumber::mter_ye1(mA);
	Unumber::mter_ye2(mB);

	__asm__ ("le3.gcd ye0,ye1,ye2");

	Unumber::mfer_ye0(mD);

	Unumber r = Unumber::importArray(mD, length);
	return r;
#endif
}

#include "meuclid.inc"
