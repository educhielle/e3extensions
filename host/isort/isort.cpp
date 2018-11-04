/* insertion sort ascending order */
#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

//#define LEN 10
#define LEN 4

int main(void)
{
    Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
    SecureInt array[LEN];
	int i, j;
    array[0] = SecureInt(__E(4),cs);
    array[1] = SecureInt(__E(2),cs);
    array[2] = SecureInt(__E(5),cs);
    array[3] = SecureInt(__E(9),cs);

    SecureInt x, y, cond1, cond2;
	for (i = 1 ; i < LEN; i++)
	{
		cout << i << ": ";
		j = i;
		while (j != 0)
		{
			cout << j << ' ' <<std::flush;
			x = array[j-1];
			y = array[j];

			cond1 = y <= x;
            cond2 = x < y;
			array[j-1] = cond1 * y + cond2 * x; //cond1.mux(y, x); // min
			array[j] = x + y - array[j-1]; //cond.mux(x, y); // max

			j--;
		}
		cout << std::endl;
	}
	cout << std::endl;

	for (i = 0; i < LEN; i++) cout << array[i].str() << " ";
	cout << std::endl;

	return 0;
}
