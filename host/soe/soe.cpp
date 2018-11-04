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

SecureInt *pzero, *pone;
SecureInt *ptwo;

void sieveOfEratosthenes(SecureInt ret[], SecureInt prime[], int n)
{
	for (int i = 0 ; i < n+1 ; i++)
        	prime[i] = *pone;

	for (int p = 2; p*p < n+1 ; p++)
	{
		cout<<' '<<p<<std::flush;
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = *pzero;
	}
	cout<<'\n';

	SecureInt pe = *ptwo;
	for (int p = 2; p < n+1; ++pe, p++)
		ret[p] = pe * prime[p];
}

int main(void)
{
	Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
	SecureInt zero=SecureInt(__E(0),cs), two=SecureInt(__E(2),cs);
	SecureInt bzero=SecureInt(__E(1),cs), bone=SecureInt(__E(1),cs);
	// calls string parser

	// SecureBool test_one(two); // calls reduction

	pzero = &bzero;
	pone = &bone;
	ptwo = &two;

	int n = 30;
	SecureInt prime[n+1];
	SecureInt ret[n+1];
	for (int i=0; i<n+1; i++) ret[i]=zero;

	sieveOfEratosthenes(ret,prime,n);

	for (int p = 2; p < n+1; p++)
		cout << ret[p].str() << ' ';
	cout<<std::endl;
	return 0;
}
