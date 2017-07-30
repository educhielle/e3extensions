#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define LEN 9

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

void quickSort(SecureInt[], int, int);
int partition(SecureInt[], int, int);
void swap(SecureInt*, SecureInt*);

int main()
{
	Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt(__E(7),cs);
	a[1] = SecureInt(__E(12),cs);
	a[2] = SecureInt(__E(2),cs);
	a[3] = SecureInt(__E(0),cs);
	a[4] = SecureInt(__E(1),cs);
	a[5] = SecureInt(__E(15),cs);
	a[6] = SecureInt(__E(4),cs);
	a[7] = SecureInt(__E(11),cs);
	a[8] = SecureInt(__E(9),cs);

	int i;
	cout << "\n\nUnsorted array is:  ";
	for(i = 0; i < LEN; ++i) cout << a[i].str() << " ";
	cout << "\n";

	quickSort(a, 0, LEN-1);

	cout << "\n\nSorted array is:  ";
	for(i = 0; i < LEN; ++i) cout << a[i].str() << " ";
	cout << "\n";
}

void quickSort(SecureInt a[], int l, int r)
{
	int j;
	if( l < r ) 
	{
   		// divide and conquer
		j = partition(a, l, r);
		quickSort(a, l, j-1);
		quickSort(a, j+1, r);
	}
}

int partition( int a[], int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	
	for (int j = l; j < r; j++)
	{	
		if (a[j] < pivot) swap(&a[++i], &a[j]);
	}
	
    	if (a[r] < a[i+1]) swap(&a[i+1], &a[r]);

    	return i + 1;
}

void swap(SecureInt *a, SecureInt *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

