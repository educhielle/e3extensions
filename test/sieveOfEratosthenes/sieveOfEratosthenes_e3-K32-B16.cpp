#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

/********************************************************
** Create a boolean array "prime[0..n]" and initialize
** all entries it as true. A value in prime[i] will
** finally be false if i is Not a prime, else true.
********************************************************/

void sieveOfEratosthenes(int n) {
	Cryptosystem cs("2870703877",16,"1490953981601255182",{"6847507196622954514","3962278787439745898","4551733703680317963","3903022668731917287","4884664497744481","676879711973161723","1720642171089678603","388249188379880486","4140078465097791093","133781734683134116","6985572570576533291","4567639638261009008","7671711407114866322","4003568456144903973","8037110246977750570","4626645418983107288","1151895066976761356"},"7256027514874959049","1312718096773690775", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("4717217040824111243",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("2516492730603232105",cs);
	}

	SecureInt pe = SecureInt("4883845341139038673",cs);
	for (int p = 2; p < n+1; p++, ++pe) // Print all prime numbers
	{
		cout << (pe * prime[p]).str() << " ";
	}
	cout << "\n";
}

int main(void)
{
	int n = 30;
	sieveOfEratosthenes(n);

	return 0;
}
