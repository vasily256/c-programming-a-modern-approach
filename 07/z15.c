//int: max 12, 

#include <stdio.h>

int main(void)
{
    long n, f, i;
    
    printf("Enter a positive integer: ");
    scanf("%ld", &n);
    
    for (f = i = 1; i <= n; i++) {
        f *= i;
    }
    
    printf("Factorial of %ld: %ld\n", n, f);
    
    return 0;
}
