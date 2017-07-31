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
	Cryptosystem cs("8383037978887218593",8,{"54827265501254128759157822602703653696","40636163656648478640204526976962981185","26674967889966003532448093931071685204","23514184489214328650970136672133203120","35754479753371865094851280044263845902","58930382928926420485624077842695788520","62434351058463652327398980557087961076","35626116657396611978332291169289844623","41411677883245753013417948315860548296"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("28191981820567780739642907882072610646",cs);
	a[1] = SecureInt("60798732920883611479221222885396677469",cs);
	a[2] = SecureInt("34915586606455723480868315912008335583",cs);
	a[3] = SecureInt("57343258592684414719161788668161347767",cs);
	a[4] = SecureInt("58118205436609841638914098009010300866",cs);
	a[5] = SecureInt("41031695186319264374736433791781462568",cs);

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

