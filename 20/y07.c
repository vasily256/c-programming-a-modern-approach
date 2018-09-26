#include <stdio.h>

#define SIZE 64

char *print_bin(unsigned int val);

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
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin(i), i, i);

    printf("Enter number of places to rotate left: ");
    scanf("%d", &n);
    i = rotate_left(i, n);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin(i), i, i);

    printf("Enter number of places to rotate right: ");
    scanf("%d", &n);
    i = rotate_right(i, n);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin(i), i, i);

    return 0;
}

/* Prints binary value */
char *print_bin(unsigned int val)
{
    int i, j, b[SIZE];
    static char str[SIZE+SIZE/8-1];

    if (val != 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;
    if (i % 8)
        for (j = i; i - j < 8 - j % 8; i++)
            b[i] = 0;

    for (i--, j = 0; i >= 0; ) {
        if (!(j % 9))
            str[j++] = ' ';
        str[j++] = b[i--] + '0';

    } 
    str[j] = '\0';

    return str;
}
