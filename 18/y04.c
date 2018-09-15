#include <stdio.h>

int f(int i)
{
    static int j = 0;
    return i * j++;
}

// If f has never been called before the value of f(10) is 0.
// If f has been called five times previously the value of f(10) is 40.

int main(void)
{
    for (int i = 0; i < 5; i++)
        printf("%d ", f(10)); 
    printf("\n");
    return 0;
}
