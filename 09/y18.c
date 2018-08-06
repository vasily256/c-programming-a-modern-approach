#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m, n;
   
    printf("Enter two numbers: ");
    scanf("%d%d", &m, &n);

    printf("GCD: %d\n", gcd(m, n));
}

int gcd(int m, int n)
{
    if (!n) return m;
       
    return gcd(n, m % n);
}
