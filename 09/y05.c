#include <stdio.h>

int num_digits(int n);

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("%d digit(s)\n", num_digits(n));

    return 0;
}

int num_digits(int n)
{
    int i;

    for (i = 0; n > 0; i++)
        n /= 10;

    return i;
}
