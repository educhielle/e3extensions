#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

SecureInt *pE0, *pE3, *pE6, *pE10, *pE11, *pE15;

SecureInt jenkins_one_at_a_time_hash(const SecureInt* key, size_t length)
{
	size_t i = 0;
	SecureInt hash = *pE0;
	while (i != length)
	{
		cout << ' '<< i<< std::flush;
		hash += key[i++];
		hash += hash << *pE10;
		hash ^= hash >> *pE6;
	}
	cout << std::endl;
	hash += hash << *pE3;
	hash ^= hash >> *pE11;
	hash += hash << *pE15;
	return hash;
}

int main(void)
{
	Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
	SecureInt E0=SecureInt(__E(0),cs), E3=SecureInt(__E(3),cs), E6=SecureInt(__E(6),cs), E10=SecureInt(__E(10),cs), E11=SecureInt(__E(11),cs), E15=SecureInt(__E(15),cs);
	pE0=&E0; pE3=&E3; pE6=&E6; pE10=&E10; pE11=&E11; pE15=&E15;

	size_t length = 2;
	SecureInt array[length];
    array[0] = SecureInt(__E(1),cs);
    array[1] = SecureInt(__E(2),cs);

	SecureInt res = jenkins_one_at_a_time_hash(array, length);

	cout << "hash : " << res.str() << '\n';
	return 0;
}
