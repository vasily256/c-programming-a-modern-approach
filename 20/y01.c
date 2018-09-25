#include <stdio.h>

int main(void)
{
    unsigned short i, j, k;

    // (a)
    i = 8; j = 9;
    printf("%d ", i >> 1 + j >> 1);
    // Output: 0

    // (b)
    i = 1;
    printf("%d ", i & ~i);
    // Output: 0

    // (c)
    i = 2; j = 1; k = 0;
    printf("%d ", ~i & j ^ k);
    // Output: 1

    // (d)
    i = 7; j = 8; k = 9;
    printf("%d\n", i ^ j & k);
    // Output: 15

    return 0;
}
