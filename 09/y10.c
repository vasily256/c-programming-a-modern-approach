#include <stdio.h>

#define N 5

int largest(int a[], int n);
double average(int a[], int n);
int num_positive(int a[], int n);

int main(void)
{
    int n = N;
    int a[n], i;
    
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("The largest element is: %d\n", largest(a, n));
    printf("The average element is: %g\n", average(a, n));
    printf("The number of positive elements is: %d\n", num_positive(a, n));

    return 0;
}

int largest(int a[], int n)
{
    int i, max = a[0];

    for (i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

double average(int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += a[i];

    return (double) sum / n;
}

int num_positive(int a[], int n)
{
    int i, p = 0;

    for (i = 0; i < n; i++)
        if (a[i] > 0) p++;

    return p;
}
