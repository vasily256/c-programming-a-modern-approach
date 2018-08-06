#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y = 1.0, t, d;
    
    printf("Enter a positive number: ");
    scanf("%lf", &x);
    
    do {
        t = y;
        y = (y + x / y) / 2.0;
        d = t - y;
        d = fabs(d);
    } while (d >= .00001);
    
    printf("Square root: %g\n", y);
    
    return 0;
}
