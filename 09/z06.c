#include <stdio.h>

double polynom(double x);

int main(void)
{
    double x;

    printf("Enter value (x): ");
    scanf("%lf", &x);
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %g\n", polynom(x));
}

double polynom(double x)
{
    return x * (x * (x * (x * ( 3 * x + 2) - 5) - 1) + 7) - 6;
}
