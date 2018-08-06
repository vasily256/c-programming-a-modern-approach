#include <stdio.h>

#define N 5

int *find_largest (int a[], int n);

int main(void)
{ 
    int a[N];

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    printf("Largest: %d\n", *find_largest(a, N));

    return 0;
}

int *find_largest (int a[], int n)
{
    int *m = a;

    for (int *p = a + 1; p < a + n; p++)
        if (*p > *m)
            m = p;

    return m;
}
