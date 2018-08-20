#include <stdio.h>

#define CHECK(x,y,n) (0 <= (x) && 0 <= (y) && \
                     (x) <= (n) - 1 && (y) <= (n) - 1 ? 1 : 0)
#define MEDIAN(x,y,z) ((x) < (y) ? \
        ((z) < (x) ? (x) : (y) < (z) ? (y) : (z)) : \
        ((z) < (y) ? (y) : (x) < (z) ? (x) : (z)))
                      

int main(void)
{
    int x, y, z, n;

    printf("Enter x, y, z and n values: ");
    scanf("%d %d %d %d", &x, &y, &z, &n);

    printf("(a) Both %d and %d ", x, y);
    if (CHECK(x,y,n))
        printf("fall between 0 and %d - 1\n", n);
    else
        printf("don't fall between 0 and (%d - 1)\n", n);

    printf("(b) Median of %d, %d and %d is %d\n", x, y, z, MEDIAN(x,y,z));

    return 0;
}
