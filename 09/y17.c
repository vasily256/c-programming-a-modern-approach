// Вычисление факториала без рекурсии

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
    int f = 1;

    while (n > 0)
        f *= n--;

    return f;
}
