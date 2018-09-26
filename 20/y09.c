#include <stdio.h>

#define SIZE 64

char *print_bin(unsigned int val);

/* (a) */
int count_ones_a(unsigned char ch)
{
    int count = 0;

    do {
        if (ch & 0x1)
            count++;
    } while (ch >>= 1);

    return count;
}

/* (b) */
int count_ones_b(unsigned char ch)
{
    return (ch & 0x1) + (ch >> 1 & 0x1) + (ch >> 2 & 0x1)
                      + (ch >> 3 & 0x1) + (ch >> 4 & 0x1)
                      + (ch >> 5 & 0x1) + (ch >> 6 & 0x1)
                      + (ch >> 7 & 0x1);
}

int main(void)
{
    unsigned char i;

    printf("Enter a value i: ");
    scanf("%c", &i);
    printf("In binare: %s. In hexadecimal: %x. In decimal: %u\n", print_bin(i), i, i);
    printf("Number of ones (a): %d\n", count_ones_a(i));
    printf("Number of ones (b): %d\n", count_ones_b(i));

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
