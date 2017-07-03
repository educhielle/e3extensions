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
	Cryptosystem cs("205824912770119148895258210573375324581","8","17575704278692039750007076663931085758575085276835932593968793007549826011858","37661556289834543740161312908748652493925982843721594143931025584114555184131","41906433655442133542234335937299973123509216159102125804889150918863687252458", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("27829773291299509313203188698795298889008210190814607839942081607542748579919",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("19338548998627626231085755307896084727239071634220378425339309191150022117641",cs);
	}

	SecureInt pe = SecureInt("6532400814249618429345966059164750415343170965159223852228417894880640512045",cs);
	for (int p = 2; p < n+1; p++, ++pe) // Print all prime numbers
	{
		cout << (pe * prime[p]).str() << " ";
	}
	cout << "\n";
}

int main(void)
{
	int n = 100;
	sieveOfEratosthenes(n);

	return 0;
}
