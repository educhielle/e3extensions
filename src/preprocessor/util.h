#ifndef UNUMBER_INCLUDED
	#define UNUMBER_INCLUDED
	#include "../unumber/unumberg.h"
#endif

#ifndef RANDOM_INCLUDED
	#define RANDOM_INCLUDED
	#include <random>
#endif

Unumber invertibleRandom(Unumber from, Unumber n)
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

		/* the number is valid if it is a number in the range [1,n-1]
		 * and its gcd with n is one */
		if ((number < n) && (ma::gcd(number, n) == 1)) break;
	}

	return number;
}

