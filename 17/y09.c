// x.a is the same as (&x)->a

#include <stdio.h>

int main(void)
{
    struct {
        int a;
    } x = {5};

    printf("x.a = %d, (&x)->a = %d\n", x.a, (&x)->a);

    return 0;
}
