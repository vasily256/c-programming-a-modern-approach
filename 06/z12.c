#include <stdio.h>

int main(void)
{
    double e = 1.0, p;
    
    printf("Enter accuracy of the value: ");
    scanf("%lf", &p);
    
    for (double i = 1.0, f = 1.0, t = 1.0; p < t; i++) {
        e += (t = 1.0 / (f *= i));
    }
    
    printf("Constant e is: %.15f\n", e);
    
    return 0;
}
