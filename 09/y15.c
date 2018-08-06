#include <stdio.h>

double median(double x, double y, double z);

int main(void)
{
    double x, y, z;
   
    printf("Enter 3 numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("Median: %g\n", median(x, y, z));
}

double median(double x, double y, double z)
{
    double m;

    if (x <= y <= z)
        m = y;
    else if (y <= x <= z)
        m = x;
    else
        m = z;

    return m;
}
