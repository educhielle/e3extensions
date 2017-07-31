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
	Cryptosystem cs("2243656321",26,{"3661883537953332371","1149566970823710886","49666438610121935","1101176028570777652","4952318178842376045","4509276718374629340","3124006485001243913","1926065348847961523","3197398008554095328","2067668366657210963","3971119693775741356","4180898949104239650","2023520221625498837","1146716586989598971","3861657012538947984","2565132261606230859","2476451606318926572","4785969823631912241","3182855058301859071","2317348011601298865","159342561182759121","2293254989969119887","657044230187096509","2705177555912315520","3015231181057317207","833653749502151035","4280781859163519542"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("2692486006211805964",cs);
	a[1] = SecureInt("3504850907391455458",cs);
	a[2] = SecureInt("4789106532095118708",cs);
	a[3] = SecureInt("180000713525370679",cs);
	a[4] = SecureInt("1501231622632978210",cs);
	a[5] = SecureInt("1130511540599364589",cs);

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

