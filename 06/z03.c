#include <stdio.h>

int main(void)
{
    int num, den, n, d, r;
    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);
    
    n = num;
    d = den;
    while (d != 0) {
        r = n % d;
        n = d;
        d = r;
    }
    
    num /= n;
    den /= n;
    printf("In lowest terms: %d/%d\n", num, den);
    
    return 0;
}
