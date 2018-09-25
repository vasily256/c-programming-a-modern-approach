#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M(x,y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

int main(void)
{
    int x, y;

    srand((unsigned) time(NULL));
    x = rand();
    y = rand();

    printf("x = %d y = %d\n", x, y);
    M(x, y);
    printf("x = %d y = %d\n", x, y);

    return 0;
}
