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
	Cryptosystem cs("11503608030940815737",8,"99007734452618730957958530423253679220",{"60558152857600537024961891022079701139","20856183570108900049926782163465537456","48385830287658952075153122538617324366","975572560603950266456401906255127843","46847374606832650760829422955814800548","83401049660661838715279570405305539908","26283136445297153669724558782461777844","19639699676399959294756330127175120381","38246303333155793979990318154357550248"},"73089644174201371683765734052726590857","39876520195202801135699430920532793634", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("99900432932847443024223005153005517004",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("25179810339766881328344193322879350605",cs);
	}

	SecureInt pe = SecureInt("83556361361739060855247304462300151491",cs);
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
