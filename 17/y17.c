#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *r);

int main(void)
{
    const int n = 100;
    int a[n]; 

    // array initialisation:
    for (int i = 0; i < n; i++)
        printf("%-3d", a[i] = n - i - 1);
    printf("\n");

    qsort(a + n / 2, n / 2, sizeof(int), compare);

    for (int i = 0; i < n; i++)
        printf("%-3d", a[i]);
    printf("\n");

    return 0;
}

int compare(const void *p, const void *r)
{
    return *((int *) p) - *((int *) r);
}
