#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;

    while (start <= end)
        sum += (*f)(start++);

    return sum;
}

int g(int value)
{
    return value;
}

int main(void)
{
    int i, j;

    printf("Enter start and end values: ");
    scanf("%d%d", &i, &j);

    printf("Result: %d\n", sum(g, i, j));

    return 0;
}
