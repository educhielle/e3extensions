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
	Cryptosystem cs("3381175157",8,{"9403332115005475983","623106787918890934","1742274322210811510","10041819638653604324","10830770215263503886","9847066545193601269","5802348043211249768","5292155961779416306","3814853377919019389"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("1458607050771720464",cs);
	a[1] = SecureInt("6045844526039827946",cs);
	a[2] = SecureInt("1217785246750578901",cs);
	a[3] = SecureInt("4162959222723810642",cs);
	a[4] = SecureInt("6833149683995292511",cs);
	a[5] = SecureInt("6154521063441679587",cs);

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

