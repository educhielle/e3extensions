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
	Cryptosystem cs("2371286461",27,"2524152938782620915",{"2344853748432381471","3051875849287152395","4799835327067955385","315397853044285860","1072015049766771718","2355218918987200917","901663192429900586","4197909140724310134","2687420468537338873","3401763593291496176","309501716044713781","3960382787924012513","3458116902174761537","1824193027385994992","1673654176010183974","3832682157443609897","4141607869347855185","1193633218980842807","3977072302519061756","969033416950866682","1991130745986626015","494403111634354688","2663470083087730655","896546652210746143","2281013712489469681","2124281813701274080","5521824924592388615","1625918250466981519"},"4572315438308642533","1170428161627823843", libgDir, gFunctionName);

	SecureInt prime[n+1];
	for (int i = 0 ; i < n+1 ; i++) 
        	prime[i] = SecureInt("4052535445699951773",cs);

	for (int p = 2; p*p < n+1 ; p++)
	{
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = SecureInt("1583671949981211430",cs);
	}

	SecureInt pe = SecureInt("2543520340699968905",cs);
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
