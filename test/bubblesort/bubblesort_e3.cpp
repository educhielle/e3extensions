#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define LEN 6

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

void bubbleSort(SecureInt[], int);
void printArray(SecureInt[], int);
void swap(SecureInt*, SecureInt*);
 
// Driver program to test above functions
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

	bubbleSort(a, LEN);

	cout << "Sorted array is:  ";
	printArray(a, LEN);

	return 0;
}

// A function to implement bubble sort
void bubbleSort(SecureInt arr[], int n)
{
	int i, j;
	SecureInt cond1, cond2, smaller, greater;

	for (i = 0; i < n-1; i++)
	{
		// Last i elements are already in place   
		for (j = 0; j < n-i-1; j++)
		{
			cond1 = arr[j] <= arr[j+1];
			cond2 = arr[j+1] < arr[j];
			smaller = cond1 * arr[j] + cond2 * arr[j+1];
			greater = arr[j+1] + arr[j] - smaller;
			arr[j] = smaller;
			arr[j+1] = greater;
		}
	}
}


/* Function to print an array */
void printArray(SecureInt arr[], int size)
{
	for (int i=0; i < size; i++) cout << arr[i].str() << " ";
	cout << "\n";
}


void swap(SecureInt *xp, SecureInt *yp)
{
	SecureInt temp = *xp;
	*xp = *yp;
	*yp = temp;
}

