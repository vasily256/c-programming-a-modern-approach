#include <stdio.h>

#define SIZE 64

char *print_bits2(unsigned int val);

int main(void)
{
    /* Original version */
    struct {
        int flag: 1;
    } s;

    /* Fixed version */
    struct {
        unsigned int flag: 1;
    } t;

    s.flag = 1;
    printf("Flag: %2d. Value in binary: %s\n", s.flag,  print_bits2(s.flag));

    t.flag = 1;
    printf("Flag: %2d. Value in binary: %s\n", t.flag,  print_bits2(t.flag));

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
