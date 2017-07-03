/* insertion sort ascending order */
#include <iostream>
#include "../../src/e3extensions/secureint.h"

using namespace std;

string libgDir = "./libg.so";
string gFunctionName = "libg";
 
// swap if the second is greater
void minswp(int *x, int *y) {
    if (*x < *y) {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
}

int gfun(int x, int y) {
    return (x <= 0) ? 0 : y;
}

int main(void) {
    int n = 20, j;
    int array[20] = { 4, 2, 5, 7, 1, 0, 11, 3, 9, 8, 4, 5, 6, 1, 2, 3, 7, 9, 10, 2 };
    int *arrayPrev = array;
    int *arrayCur = array;

    int i = 1;
    outer_loop:
        j = i;
        arrayCur = array + i;
        inner_loop:
            arrayPrev = arrayCur-1;
            minswp(arrayCur, arrayPrev);
            j--;
            arrayCur--;
        if (j != 0) goto inner_loop;
        i++;
    if (i != n) goto outer_loop;

    for (i = 0; i < n; i++)
        printf("%d  ", array[i]);
    printf("\n");
    return 0;
}

