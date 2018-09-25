#include <stdio.h>

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
    int i, b[64];
    static char str[64];

    if (val != 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;

    str[i--] = 0;
    for (int j = 0; i >= 0; i--, j++)
        str[j] = b[i] + '0';

    return str;
}
