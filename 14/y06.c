#include <stdio.h> 
#include <math.h> 

#define DISP(f,x) printf(#f "(%g) = %g\n", x, f(x))               // (a)
#define DISP2(f,x,y) printf(#f "(%g, %g) = %g\n", x, y, f(x, y))  // (b)

double avg(double x, double y)
{
    return (x + y) / 2;
}

int main(void)
{
    double x, y;

    printf("Enter x and y values: ");
    scanf("%lf %lf", &x, &y);

    DISP(sqrt, x);
    DISP2(avg, x, y);

    return 0;
}
