#include <stdio.h>

int main(void)
{
    int n, a0, a1, a2, b, r;
    
    printf("Enter a three-digit number: ");
    scanf("%3d", &n);
    
    a2 = n / 100;
    b = n % 100;
    a1 = b / 10 * 10;
    a0 = b % 10 * 100;
    r = a0 + a1 + a2;
    
    printf("The reversal is: %.3d\n", r);
    
    return 0;
}
