#include <stdio.h>

#define SIZE 64

char *print_bits(int val);

int main(void)
{
    int n, i;

    printf("Enter a value: ");
    scanf("%d", &n);

    printf("In binare before toggle: %s\n", print_bits(n));

    printf("Enter number of bit to be toggled: ");
    scanf("%d", &i);

    n ^= 0x1 << i;
    printf("In binare after toggle:  %s\n", print_bits(n));

    return 0;
}

/* Prints bits of binary value */
char *print_bits(int val)
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
