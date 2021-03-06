#include <stdio.h>
 
#define MAX_NUM 50
#define NUM 5

int main(void) {
    asm("l.debug");
    int fact = 1;
    int i = 1;
    int result;
    do {
        fact *= i;
        result += (i == NUM) * fact;
    } while (++i != MAX_NUM);
    printf("fact(%d) = %d\n", NUM, result);
    asm("l.debug");
    return 0;
}
