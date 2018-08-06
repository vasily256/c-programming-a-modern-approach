// The program returns a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]

#include <stdio.h>

#define N 5

double inner_product(double a[], double b[], int n);

int main(void)
{
    int n = N, i;
    double a[n], b[n]; 
    
    printf("Enter %d numbers (double) of array 'a': ", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    printf("Enter %d numbers (double) of array 'b': ", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    printf("Result: %g\n", inner_product(a, b, n));

    return 0;
}

double inner_product(double a[], double b[], int n)
{
    int i;
    double result = 0.0;

    for (i = 0; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}
