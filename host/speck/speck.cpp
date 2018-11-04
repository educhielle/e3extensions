#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

// #define EDS Secure::size()

#define ROUNDS 11  // 22
#define KEY_LEN 4

SecureInt *pE0, *pE1, *pE2, *pE7, *pEEDS;

//#define ROR(x, r) ((x >> r) | (x << ((sizeof(uint16_t) * 8) - r)))
//#define ROL(x, r) ((x << r) | (x >> ((sizeof(uint16_t) * 8) - r)))
#define ROR(x, r) ((x >> r) | (x << (*pEEDS - r)))
#define ROL(x, r) ((x << r) | (x >> (*pEEDS - r)))
#define R(x, y, k) (x = ROR(x, *pE7), x += y, x ^= k, y = ROL(y, *pE2), y ^= x)

void speck_expand(SecureInt K[KEY_LEN], SecureInt S[ROUNDS])
{
	SecureInt b = K[0];
	SecureInt a[KEY_LEN - 1];

	for (int i = 0; i < KEY_LEN - 1 ; i++)
	{
		a[i] = K[i + 1];
	}

	S[0] = b;
	SecureInt ei = *pE0;
	for (int i = 0; i < ROUNDS - 1; i++, ei+=*pE1)
	{
		cout<<' '<<i<<std::flush;
		R(a[i % (KEY_LEN - 1)], b, ei);
		S[i + 1] = b;
	}
	cout << std::endl;
}

int main(void)
{
	Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
	SecureInt E0 = SecureInt(__E(0),cs);
	SecureInt E1 = SecureInt(__E(1),cs);
	SecureInt E2 = SecureInt(__E(2),cs);
	SecureInt E7 = SecureInt(__E(7),cs);
	SecureInt EEDS = SecureInt(__E(32),cs);
	pE0=&E0; pE1=&E1; pE2=&E2; pE7=&E7; pEEDS=&EEDS;

	SecureInt key[KEY_LEN], exp[ROUNDS];
	key[0] = SecureInt(__E(256),cs);
	key[1] = SecureInt(__E(2312),cs);
	key[2] = SecureInt(__E(4368),cs);
	key[3] = SecureInt(__E(6424),cs);

	speck_expand(key, exp);

	for (int i = 0; i < ROUNDS; ++i)
		cout << exp[i].str() << '\n';
	return EXIT_SUCCESS;
}
