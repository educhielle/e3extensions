#ifndef UNUMBEZ_H__
#define UNUMBEZ_H__

#include <sstream>
#include <string>
#include <ostream>
#include <istream>
#include <cctype>
#include <cstring>

#include <stddef.h>
#include <gmpxx.h>

using std::string;

class Unumber
{
        mpz_class z;
        void neg();
        void pos();

        static const int MOD_POWER = 4096;
        static Unumber MOD_VALUE;
        static void init_mod_value();

    public:
        static const size_t LENGTH = 64;

        Unumber(unsigned long long x);
        Unumber();

         enum StringType { Binary, Decimal, Hexadecimal };
        Unumber(const string & s, StringType st);
	Unumber(const string & s, unsigned int base=0);
	Unumber(const Unumber & n);

	void init(const char *, unsigned);
        void init10(const char * s);
        void initBin(const string & s);

        void operator-=(const Unumber & n);
        void operator+=(const Unumber & n);
        void operator*=(const Unumber & n);
        void operator%=(const Unumber & n);
        void operator/=(const Unumber & n);

        void setbit1(int b);
        unsigned getbit(int b) const;

        void pow(Unumber e, const Unumber & mod);

        Unumber div(const Unumber & d, Unumber & q) const;

        Unumber mul(const Unumber & b, const Unumber & m) const;

        void divABRQ(const Unumber & d, Unumber * r, Unumber * q) const;

        bool iszero() const;

        Unumber & operator++();
        Unumber & operator--();

        void operator<<=(int b);
        void operator>>=(int b);

        friend Unumber operator-(const Unumber & n1, const Unumber & n2)
        { Unumber r(n1); r -= n2; return r; }

        friend Unumber operator*(const Unumber & n1, const Unumber & n2)
        { Unumber r(n1); r *= n2; return r; }

        friend Unumber operator+(const Unumber & n1, const Unumber & n2)
        { Unumber r(n1); r += n2; return r; }

        friend Unumber operator%(const Unumber & n1, const Unumber & n2)
        { Unumber r(n1); r %= n2; return r; }

        friend Unumber operator/(const Unumber & n1, const Unumber & n2)
        { Unumber r(n1); r /= n2; return r; }

        friend bool operator<(const Unumber & n1, const Unumber & n2);

	friend bool operator<=(const Unumber & n1, const Unumber & n2)
	{ return ((n1 < n2) || (n1 == n2)); }

        friend bool operator>(const Unumber & n1, const Unumber & n2) { return n2 < n1; }

	friend bool operator>=(const Unumber & n1, const Unumber & n2)
	{ return ((n1 > n2) || (n1 == n2)); }

        friend bool operator!=(const Unumber & n1, const Unumber & n2)
        { return !(n1 == n2); }

        friend bool operator==(const Unumber & n1, const Unumber & n2)
        { return n1.z == n2.z; }

        void swap(Unumber & n) { mpz_class t = z; z=n.z; n.z=t; }

        string str(unsigned base=10) const;
        unsigned long long to_ull() const;

        friend std::ostream & operator<<(std::ostream & os, const Unumber & n)
        { return (os << n.str()); }

        friend std::istream & operator>>(std::istream & os, Unumber & n);

        string raw(unsigned sz) const;

        /* Unique CoPHEE functions (based on hwacc) */
        static int pd;
        static Unumber invertibleRandom(const Unumber & n);
        static Unumber gmpmul(const Unumber & a, const Unumber & b);
        static void initCophee();
        static void resetCounters();
        // static unsigned long long getTimeSerial();
        // static unsigned long long getTimeMul();
        // static unsigned long long getTimeExp();
        // static unsigned long long getTimeInv();
        // static unsigned long long getTimeGfun();
        static void showTimes();

        static void exportArray(unsigned[], unsigned, Unumber);
    	static Unumber importArray(unsigned[], unsigned);

    	static Unumber hw_modmul(const Unumber & x, const Unumber & y);
    	static Unumber hw_modexp(const Unumber & x, const Unumber & y);

    	static Unumber hw_gcd(const Unumber & x, const Unumber & y);
    	static Unumber hw_inv(const Unumber & x, const Unumber & y);

    	static Unumber hw_gfun(const Unumber & x, const Unumber & y);
};


inline Unumber operator>>(Unumber a, unsigned b) { a >>= b; return a; }
inline Unumber operator<<(Unumber a, unsigned b) { a <<= b; return a; }

#endif
