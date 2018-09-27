#include <stdio.h>

#define SIZE 64

char *print_bits2(unsigned int val);

unsigned int rotate_left(unsigned int i, int n)
{
    unsigned int bit;

    if (n > 0)
        while (n-- > 0) {
            bit = i >> sizeof(i) * 8 - 1;
            i = (i << 1) + bit;
        }
    else
        while (n++ < 0) {
            bit = (i & 0x1) << sizeof(i) * 8 - 1;
            i = (i >> 1) + bit;
        }

    return i;
}

unsigned int rotate_right(unsigned int i, int n)
{
    unsigned int bit;

    if (n > 0)
        while (n-- > 0) {
            bit = (i & 0x1) << sizeof(i) * 8 - 1;
            i = (i >> 1) + bit;
        }
    else
        while (n++ < 0) {
            bit = i >> sizeof(i) * 8 - 1;
            i = (i << 1) + bit;
        }

    return i;
}

int main(void)
{
    unsigned int i;
    int n;

    printf("Enter a value: ");
    scanf("%u", &i);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits2(i), i, i);

    printf("Enter number of places to rotate left: ");
    scanf("%d", &n);
    i = rotate_left(i, n);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bits2(i), i, i);

    printf("Enter number of places to rotate right: ");
    scanf("%d", &n);
    i = rotate_right(i, n);
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
