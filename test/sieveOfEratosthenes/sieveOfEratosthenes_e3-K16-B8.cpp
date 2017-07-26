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
	Cryptosystem cs("34393",8,"1169144488",{"929542023","4437282","686412448","46974205","411562231","1103733443","516138010","1072980798","71379300"},"400150089","1116913021", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("25364994",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("1077825253",cs);
	}

	SecureInt pe = SecureInt("765219857",cs);
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
