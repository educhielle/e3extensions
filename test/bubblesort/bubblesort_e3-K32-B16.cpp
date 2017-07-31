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
	Cryptosystem cs("1912866353",16,{"1210016313722224088","981957140664349117","2224933311783583820","1481649277918648245","1257240657115600604","3380613593555666715","1382447879777801770","3544029103422009402","1626967170796101337","730867496795559899","3352756368067972229","1782162425991213276","567736678906493329","2784126303676261258","903489246785397839","3374288376638477870","1468142062492380773"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("920214237967004666",cs);
	a[1] = SecureInt("1333793309620013338",cs);
	a[2] = SecureInt("534027183379600265",cs);
	a[3] = SecureInt("370055741764448327",cs);
	a[4] = SecureInt("1968868597414278688",cs);
	a[5] = SecureInt("3419533387997265326",cs);

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

