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
	Cryptosystem cs("52961",14,"1244754592",{"150788191","2548713871","1345476529","1877204425","368799053","1136893733","191284026","663436306","416975755","2110033859","2012695944","823641467","2749639803","1068053643","475440041"},"148166140","1410011812", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("2152560625",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("1335216347",cs);
	}

	SecureInt pe = SecureInt("1831022459",cs);
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
