#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int a[N], i, big, small;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    max_min(a, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);
}

void max_min(int a[], int n, int *max, int *min)
{
    int i;

    *max = *min = a[0]; 
    for (i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        } else if (a[i] < *min) {
            *min = a[i];
        }
    }
}
