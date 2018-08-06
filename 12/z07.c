#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int a[N], i, max, min;

    printf("Numbers: ");
    srand((unsigned) time(NULL));
    for (i = 0; i < N; i++) {
        printf("%d ", a[i] = rand() % 1000);
    }
    printf("\n");

    max_min(a, N, &max, &min);

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
}

void max_min(int a[], int n, int *max, int *min)
{
    int count = 1;
    *max = *min = a[0]; 
    for (int *p = a + 1; p < a + n; p++) {
        if (*p > *max) {
            *max = *p;
        } else if (*p < *min) {
            *min = *p;
        }
        printf("%d max: %d min: %d\n", count++, *max, *min);
    }
}
