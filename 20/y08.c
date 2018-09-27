#include <stdio.h>

#define SIZE 64

char *print_bits(unsigned int val);

unsigned int f(unsigned int i, int m, int n)
{
    return (i >> (m + 1 - n)) & ~(~0 << n);
}

int main(void)
{
    unsigned int i;
    int m, n;

    printf("Enter a value i: ");
    scanf("%u", &i);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits(i), i, i);

    printf("Enter a value m: ");
    scanf("%d", &m);
    printf("Enter a value n: ");
    scanf("%d", &n);

    i = f(i, m, n);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits(i), i, i);

    return 0;
}

/* Prints bits of binary value */
char *print_bits(unsigned int val)
{
    int i, j, k, b[SIZE];
    static char str[SIZE+SIZE/8];

    if (val > 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;

    if (i % 8) {
        for (j = i; i - j < 8 - j % 8; i++) {
            b[i] = 0;
        }
    }

    for (j = i - 1, i = 0, k = 1; j >= 0; ) {
        str[i++] = b[j--] + '0';
        if (!(k++ % 8))
            str[i++] = ' ';
    }
    str[--i] = '\0';

    return str;
}
