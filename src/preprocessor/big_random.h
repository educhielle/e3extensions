#ifndef RANDOM_INCLUDED
	#define RANDOM_INCLUDED
	#include <random>
#endif

#ifndef UNUMBER_INCLUDED
	#define UNUMBER_INCLUDED
	#include "../unumber/unumberg.h"
#endif

Unumber invertibleRandom(const Unumber &, const Unumber &);
bool millerRabin(const Unumber &, int);
Unumber oddRandom(const Unumber &, const Unumber &);
Unumber prime();
Unumber random(const Unumber &, const Unumber &);

/* Generate a random number in the range [from,n-1] that has no common divisor with n */
Unumber invertibleRandom(const Unumber & from, const Unumber & n)
{
	unsigned high_bit_posN = 0;
	Unumber x = n - 1;
	while (x != 0) { x >>= 1; high_bit_posN++; }
	high_bit_posN--;

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

		/* the number is valid if it is a number in the range [from,n-1]
		 * and its gcd with n is one */
		if ((number < n) && (ma::gcd(number, n) == 1) && (from <= number)) break;
	}

	return number;


	/* another option (more modular, lower performance)
	Unumber number;
	do
		number = random(from, n);
	while (ma::gcd(number, n) =! 1);
	return number;
	*/
}

/* Miller-Rabin prime test */
bool millerRabin(Unumber p, int iteration=64)
{
	if ((p < 2) || (p != 2 && p % 2 == 0)) return false;
	
	Unumber s = p - 1;
    	while (s % 2 == 0) s /= 2;
	
	for (int i = 0; i < iteration; i++)
	{
		Unumber mod = random(2, p-1) % (p - 1) + 1, temp = s;
//		Unumber mod (a);
		mod.pow(temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1)
		{
			mod.mul(mod, p);
			temp *= 2;
		}

		if (mod != p - 1 && temp % 2 == 0)
		{
			return false;
		}
    	}

	return true;
}

/* Generate a random odd number in the range [from,n-1] */
Unumber oddRandom(const Unumber & from, const Unumber & n)
{
	//return (random(from,n) || 1); // || not implemented
	Unumber number = random(from,n);

	if (number % 2 == 0)
	{
		number -= 1;
		if (number < from) number += 2;
	}

	return number;
}

/* Generate a prime number in the interval [from, to-1] */
Unumber prime(Unumber from, Unumber to)
{
	Unumber p;

	do
	{
		p = oddRandom(from, to);
	} while (!millerRabin(p));
	
	return p;
}

/* Generate a random number in the range [from,n-1] */
Unumber random(const Unumber & from, const Unumber & n)
{
	unsigned high_bit_posN = 0;
	Unumber x = n - 1;
	while (x != 0) { x >>= 1; high_bit_posN++; }
	high_bit_posN--;

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
		 * However, any random number > (n-1) or < (from) needs to be ignored.
		 * If "count - high_bit_posN" is used instead,
		 * the range of random numbers is [from,x], where x < (n-1),
		 * but it is faster. */
		unsigned shift = count - high_bit_posN - 1;
		number >>= shift;

		/* the number is valid if it is a number in the range [from,n-1] */
		if ((number < n) && (from <= number)) break;
	}

	return number;
}

