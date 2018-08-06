#include <stdio.h>

int fact(int n);

int main(void)
{
    int n;
   
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Fact: %d\n", fact(n));
}

int fact(int n)
{
    return n == 1 ? 1 : n * fact(n - 1);
}
