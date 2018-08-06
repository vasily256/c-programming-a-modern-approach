#include <stdio.h>

#define N 10

int *find_largest(int a[], int n);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    } 

    printf("Largest: %d\n", *find_largest(a, N));

    return 0;
}

int *find_largest(int a[], int n)
{
    int *max = &a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            max = &a[i];
        }
    }
    return max;
}
