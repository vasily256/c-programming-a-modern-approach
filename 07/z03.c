#include <stdio.h>

int main(void)
{
    double n, sum = 0.0;
    
    printf("This program sums a series of double volumes.\n");
    printf("Enter double volume (0 to terminate): \n");
    
    scanf("%lf", &n);
    while(n != 0.0) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %.15f\n", sum);
    
    return 0;
}
