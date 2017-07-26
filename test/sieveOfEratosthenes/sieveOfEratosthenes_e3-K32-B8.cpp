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
	Cryptosystem cs("2304177853",8,"910484172747174750",{"1235589090945016076","3184472863966616771","1079230115205369690","4912430116625002123","4136234824452485048","76199434190225540","1006894551735426259","5171702131492906757","1320654989081095787"},"776565738381750019","2880222640199142478", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("343184717811160980",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("5188764326832842699",cs);
	}

	SecureInt pe = SecureInt("4902035141364810642",cs);
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
