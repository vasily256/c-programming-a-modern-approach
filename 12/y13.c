#include <stdio.h>

#define N 5

int main(void)
{
    double ident[N] [N];

    for (double *ptr = ident[0]; ptr < ident[N]; ptr++)
        if ((ptr - ident[0]) % (N + 1) == 0)
            *ptr = 1.0;
        else
            *ptr = 0.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%g ", ident[i] [j]);
        printf("\n");
    }
}
