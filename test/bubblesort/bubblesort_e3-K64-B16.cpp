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
	Cryptosystem cs("9479689654718562649",16,{"35065839166945184523044093259296776113","82190443395654252932164234744201909184","45442548857152205625454226667795715803","41939943170295402589686387005896623481","82566031314243865146144462009907176051","59107740748477342122301466169110444051","31441721489456804992717514028684048963","15170003217045456677445166600597082142","66308223240487068058757160110178537278","57011324446768352355390124086284566926","17350356590528888341487139004222786454","2617486018565297542563540080803869031","20450299047583518074858098954586566295","14128947119361518725552845667160582304","57302744236390055321779719150685543294","45882264288098441788739468643965675073","70867249186295509692080397798232988859"}, libgDir, gFunctionName);
	SecureInt a[LEN];

	a[0] = SecureInt("12407433618093245867667965342523923409",cs);
	a[1] = SecureInt("74663904921565947964831292693782764139",cs);
	a[2] = SecureInt("47176100507687047183850256148090810174",cs);
	a[3] = SecureInt("2137272024312978027118908645365128675",cs);
	a[4] = SecureInt("45422761607062781096183794688956595829",cs);
	a[5] = SecureInt("32592713661457685164456802085918826008",cs);

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

