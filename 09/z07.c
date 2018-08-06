#include <stdio.h>

int power(int a, int n);

int main(void)
{
    int a, n;

    printf("Enter value (a): ");
    scanf("%d", &a);
    printf("Enter a power: ");
    scanf("%d", &n);
    printf("%d^%d = %d\n", a, n, power(a, n));
}

int power(int a, int n)
{
    int b;

    if (n == 0)
        return 1;
    else if (n % 2 == 0) {
        b = power(a, n / 2);
        return b * b;
    } else
        return a * power(a, n - 1);

}
