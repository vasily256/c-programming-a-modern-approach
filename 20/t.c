#include <stdio.h>
#define SIZE 64

char *print_bin2(unsigned int val);

int main(void)
{
    const int max_bits = sizeof(unsigned int) * 8;
    unsigned int r = 0x0, bit = 0x1, n = ~0;
    int i = 16;

    printf("%3d          %s\n", i, print_bin2( (n & bit << i) ));

    r = (n & bit << i) << max_bits - 2 * i - 1;
    printf("%3d %8x %s\n\n", i, r, print_bin2(r) );

    r = 0;
    for (i = 0; i < max_bits; i++) {
        r |= (n & bit << i) << max_bits - 2 * i - 1;
        printf("%3d %8x %s\n", i, r, print_bin2(r) );
    }

    return 0;
}

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
