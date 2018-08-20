#include <stdio.h>

void f(void);

int main(void)
{
    f();
    return 0;
}

void f(void)
{
    printf("N is undefined\n");
}
