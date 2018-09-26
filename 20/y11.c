#include <stdio.h>

#define SIZE 64
#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

char *print_bits(unsigned int val);

int main(void)
{
    unsigned char key_code;

    printf("Enter a two-digit hexadecimal value: ");
    scanf("%x", &key_code);
    printf("In binary: %s. In hexadecimal: %x. In decimal: %u\n", print_bits(key_code), key_code, key_code);

    /* Original version 
    if (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0)
        printf("No modifier keys pressed\n");
    */

    /* Fixed version */
    if ((key_code & (1 << SHIFT_BIT | 1 << CTRL_BIT | 1 << ALT_BIT)) == 0)
        printf("No modifier keys pressed\n");

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
