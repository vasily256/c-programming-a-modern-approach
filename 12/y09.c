#include <stdio.h>

#define N 5

double inner_product(const double *a, const double *b, int n);

int main(void)
{ 
    double a[N], b[N];

    printf("Enter %d numbers of array 'a': ", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &a[i]);
    }

    printf("Enter %d numbers of array 'b': ", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &b[i]);
    }

    printf("Inner product: %g\n", inner_product(a, b, N));

    return 0;
}

double inner_product(const double *a, const double *b, int n)
{
    double product = 0.0;

    for (const double *pa = a, *pb = b; pa < a + n; pa++, pb++)
        product += *pa * *pb;

    return product;
}
