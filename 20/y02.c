#include <stdio.h>

#define SIZE 64

char *print_bin(int val);

int main(void)
{
    int n, i;

    printf("Enter a value: ");
    scanf("%d", &n);

    printf("In binare before toggle: %s\n", print_bin(n));

    printf("Enter number of bit to be toggled: ");
    scanf("%d", &i);

    n ^= 0x1 << i;
    printf("In binare after toggle:  %s\n", print_bin(n));

    return 0;
}

char *print_bin(int val)
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
