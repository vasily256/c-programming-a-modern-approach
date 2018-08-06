#include <stdio.h>

int digit(int n, int k);

int main(void)
{
    int n, k;
    
    printf("Enter a number and position: ");
    scanf("%d%d", &n, &k);

    printf("Digit N %d is: %d\n", k, digit(n, k));

    return 0;
}

int digit(int n, int k)
{
    for (; k > 1; k--)
        n /= 10;

    return n %= 10;
}
