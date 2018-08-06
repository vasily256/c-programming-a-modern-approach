#include <stdio.h>

int main(void)
{
    int n;
    double e = 1.0;
    
    printf("Enter number: ");
    scanf("%d", &n);
    
    for (double i = 1.0, f = 1.0; i <= n; i++) {
        e += 1.0 / (f *= i);
    }
    
    printf("Constant e is: %.15f\n", e);
    
    return 0;
}
