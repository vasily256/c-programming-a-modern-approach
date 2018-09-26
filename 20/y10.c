#include <stdio.h>

#define SIZE 64

char *print_bin2(unsigned int val);

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
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin2(i), i, i);

    i = reverse_bits(i);
    printf("After reversing of bits: \n");
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin2(i), i, i);

    return 0;
}

/* Prints binary value */
/* Version 2 */
char *print_bin2(unsigned int val)
{
    int n = sizeof(unsigned int) * 8;
    static char str[SIZE+SIZE/8];
    int i, j, b[SIZE];

    if (val != 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;
    while (i < n)
        b[i++] = 0;

    for (i--, j = 0; i >= 0; ) {
        if (!(j % 9))
            str[j++] = ' ';
        str[j++] = b[i--] + '0';

    } 
    str[j] = '\0';

    return str;
}
