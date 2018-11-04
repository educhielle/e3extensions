#include <iostream>
#include "../../src/e3extensions/secureint.h"
#include "timer.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";

void bubbleSort(SecureInt[], int);
void printArray(SecureInt[], int);
void sieveOfEratosthenes(SecureInt ret[], SecureInt prime[], int n);

void test_bsort(Cryptosystem & cs);
void test_fact(Cryptosystem & cs);
void test_fib(Cryptosystem & cs);
void test_isort(Cryptosystem & cs);
void test_mm(Cryptosystem & cs);
void test_soe(Cryptosystem & cs);

// Driver program to test above functions
int main()
{
    cout << "Initializing cryptosystem .. " << flush;
	Cryptosystem cs(__PQ()()()(), __BETA, __HALFTABLE, libgDir, gFunctionName);
    cout << "ok\n";

    // test_bsort(cs);
    // test_fact(cs);
    test_fib(cs);
    // test_isort(cs);
    // test_mm(cs);
    // test_soe(cs);

	return 0;
}

void test_bsort(Cryptosystem & cs)
{
    cout << "Bubble sort\n";
    const size_t LEN = 6;
    SecureInt a[LEN];
	a[0] = SecureInt(__E(7),cs);
	a[1] = SecureInt(__E(12),cs);
	a[2] = SecureInt(__E(2),cs);
	a[3] = SecureInt(__E(0),cs);
	a[4] = SecureInt(__E(1),cs);
	a[5] = SecureInt(__E(15),cs);

    Timer tmr;
	bubbleSort(a, LEN);
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

    cout << "Sorted array is:  ";
	printArray(a, LEN);
}

void test_fact(Cryptosystem & cs)
{
    cout << "Factorial\n";
    const int MAX_NUM = 10;
    SecureInt num(__E(5),cs);
	SecureInt fact(__E(1),cs);
	SecureInt i(__E(1),cs);
	SecureInt result(__E(0),cs);

    Timer tmr;
	int counter = 1;
	do {
		fact *= i;
		result += (i == num) * fact;
		++i;
	} while (++counter != MAX_NUM);
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

	cout << "fact( " << num.str() << " ) = " << result.str() << "\n";
}

void test_fib(Cryptosystem & cs)
{
    cout << "Fibonacci\n";
    const int MAX_NUM = 10;
    SecureInt num(__E(7),cs);
	SecureInt f1(__E(0),cs);
	SecureInt f2(__E(1),cs);
	SecureInt fi(__E(1),cs);
	SecureInt i(__E(1),cs);
	SecureInt result(__E(0),cs);

    Timer tmr;
	int counter = 1;
	do {
		result += (i == num) * fi;
		fi = f1 + f2;
		f1 = f2;
		f2 = fi;
		++i;
	} while (++counter != MAX_NUM);
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

	cout << "fib( " << num.str() << " ) = " << result.str() << "\n";
}

void test_isort(Cryptosystem & cs)
{
    cout << "Insertion sort\n";
    const size_t LEN = 4;
    SecureInt array[LEN];
    int i, j;
    array[0] = SecureInt(__E(4),cs);
    array[1] = SecureInt(__E(2),cs);
    array[2] = SecureInt(__E(5),cs);
    array[3] = SecureInt(__E(9),cs);

    Timer tmr;
    SecureInt x, y, cond1, cond2;
    for (i = 1 ; i < LEN; i++)
    {
        j = i;
        while (j != 0)
        {
            x = array[j-1];
            y = array[j];

            cond1 = y <= x;
            cond2 = x < y;
            array[j-1] = cond1 * y + cond2 * x; //cond1.mux(y, x); // min
            array[j] = x + y - array[j-1]; //cond.mux(x, y); // max

            j--;
        }
    }
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

    for (i = 0; i < LEN; i++) cout << array[i].str() << " ";
    cout << std::endl;
}

void test_mm(Cryptosystem & cs)
{
    cout << "Matrix multiplication\n";
    SecureInt a[3][3], b[3][3], c[3][3];

    a[0][0] = SecureInt(__E(1),cs);
    a[0][1] = SecureInt(__E(2),cs);
    a[0][2] = SecureInt(__E(3),cs);
    a[1][0] = SecureInt(__E(2),cs);
    a[1][1] = SecureInt(__E(3),cs);
    a[1][2] = SecureInt(__E(4),cs);
    a[2][0] = SecureInt(__E(3),cs);
    a[2][1] = SecureInt(__E(4),cs);
    a[2][2] = SecureInt(__E(5),cs);

    b[0][0] = SecureInt(__E(1),cs);
    b[0][1] = SecureInt(__E(2),cs);
    b[0][2] = SecureInt(__E(3),cs);
    b[1][0] = SecureInt(__E(2),cs);
    b[1][1] = SecureInt(__E(3),cs);
    b[1][2] = SecureInt(__E(4),cs);
    b[2][0] = SecureInt(__E(3),cs);
    b[2][1] = SecureInt(__E(4),cs);
    b[2][2] = SecureInt(__E(5),cs);

    Timer tmr;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = SecureInt(__E(0),cs);
            for (int k = 0; k < 3; k++) c[i][j] += a[i][k] * b[k][j];
        }
    }
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cout << c[i][j].str() << " ";
        cout << "\n";
    }
}

SecureInt *pzero, *pone;
SecureInt *ptwo;

void test_soe(Cryptosystem & cs)
{
    cout << "Sieve of Eratosthenes\n";
	SecureInt zero=SecureInt(__E(0),cs), two=SecureInt(__E(2),cs);
	SecureInt bzero=SecureInt(__E(1),cs), bone=SecureInt(__E(1),cs);
	// calls string parser

	// SecureBool test_one(two); // calls reduction

	pzero = &bzero;
	pone = &bone;
	ptwo = &two;

	int n = 30;
	SecureInt prime[n+1];
	SecureInt ret[n+1];
	for (int i=0; i<n+1; i++) ret[i]=zero;

    Timer tmr;
	sieveOfEratosthenes(ret,prime,n);
    auto tv = tmr.get();
    std::cout << "Time: " << tv << "\n";

	for (int p = 2; p < n+1; p++)
		cout << ret[p].str() << ' ';
	cout<<std::endl;
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

void sieveOfEratosthenes(SecureInt ret[], SecureInt prime[], int n)
{
	for (int i = 0 ; i < n+1 ; i++)
        	prime[i] = *pone;

	for (int p = 2; p*p < n+1 ; p++)
	{
		cout<<' '<<p<<std::flush;
		for (int i = 2*p; i < n+1 ; i += p)	// Update all multiples of p
			prime[i] = *pzero;
	}
	cout<<'\n';

	SecureInt pe = *ptwo;
	for (int p = 2; p < n+1; ++pe, p++)
		ret[p] = pe * prime[p];
}
