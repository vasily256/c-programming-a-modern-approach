#include <stdio.h>

#define SIZE 64

char *print_bits2(unsigned int val);

/* (a) */
unsigned int reverse_bits(unsigned int n)
{
    const int max_bits = sizeof(n) * 8;
    unsigned int r = 0x0, bit, test_bit = 0x1;
    int i, j;

    for (i = 0, j = max_bits - 1; i < max_bits; i++, j--) {
        bit = n & test_bit << i;
        bit >>= i;
        bit <<= j;
        r |= bit;

        /* Short wariant doesn't work!
        r |= (n & test_bit << i) << (j - i);
        */
    }

    return r;
}

int main(void)
{
    unsigned int i;

    printf("Enter a hexadecimal value i: ");
    scanf("%x", &i);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits2(i), i, i);

    i = reverse_bits(i);
    printf("After reversing of bits: \n");
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits2(i), i, i);

    return 0;
}

/* Prints bits of binary value */
/* Version 2 */
char *print_bits2(unsigned int val)
{
    int i, j, k, b[SIZE], n = sizeof(unsigned int) * 8;
    static char str[SIZE+SIZE/8];

    if (val > 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;

    while (i < n)
        b[i++] = 0;

    for (j = i - 1, i = 0, k = 1; j >= 0; ) {
        str[i++] = b[j--] + '0';
        if (!(k++ % 8))
            str[i++] = ' ';
    }
    str[--i] = '\0';

    return str;
}
