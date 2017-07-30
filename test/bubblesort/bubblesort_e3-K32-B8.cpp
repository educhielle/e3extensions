#include <iostream>
#include "../../src/e3extensions/secureint.h"

#define LEN 9

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

void bubbleSort(SecureInt[], int);
void printArray(SecureInt[], int);
void swap(SecureInt*, SecureInt*);
 
// Driver program to test above functions
int main()
{
	Cryptosystem cs("1579640737",8,{"1549974846665455832","1603940535734215266","1023882001154445459","1722649558127355172","1546286435121675169","618842391191879827","1412134949338696217","804964843593089079","375310455613152992"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("2154447957632553319",cs);
	a[1] = SecureInt("890392816372085012",cs);
	a[2] = SecureInt("270556679592579299",cs);
	a[3] = SecureInt("170022074726822464",cs);
	a[4] = SecureInt("1132104943777791535",cs);
	a[5] = SecureInt("1058586885844032448",cs);
	a[6] = SecureInt("2453600723715967972",cs);
	a[7] = SecureInt("12186135726070574",cs);
	a[8] = SecureInt("2328626679850410001",cs);


	bubbleSort(a, LEN);

	cout << "\n\nSorted array is:  ";
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

