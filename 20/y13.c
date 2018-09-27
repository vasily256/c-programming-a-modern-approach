#include <stdio.h>

#define SIZE 64

char *print_bits(unsigned int val);

int main(void)
{
    unsigned char n;

    printf("Enter two-digit hexadecimal value: ");
    scanf("%hhx", &n);
    printf("In binary %s\n\n",  print_bits(n));

    while (n > 0)
        printf("%s\n", print_bits(n &= n - 1));

    return 0;
}

/* Prints binary value */
char *print_bits(unsigned int val)
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
