#include <stdio.h>

#define N 5

void selection_sort(int a[], int n);

int main(void)
{
    int i, a[N];

    printf("Enter numbers: ");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    selection_sort(a, N);

    printf("After sorting:");
    for (i = 0; i < N; i++)
        printf(" %d", a[i]);
    putchar('\n');

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n <= 1) return;

    int i, m = 0;
    
    for (i = 0; i < n; i++)
        if (a[i] > a[m])
            m = i;

    int max = a[m];
    a[m] = a[n-1];
    a[n-1] = max;

    selection_sort(a, n - 1);
}
