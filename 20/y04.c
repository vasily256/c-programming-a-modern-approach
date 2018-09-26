#include <stdio.h>

#define SIZE 64

#define MK_COLOR(red,green,blue) \
(((red) << 16) + ((green) << 8) + (blue))

char *print_bin(int val);

int main(void)
{
    unsigned long red, green, blue;

    printf("Enter a value of red: ");
    scanf("%ld", &red);
    printf("Red in binare: %s\n", print_bin(red));

    printf("Enter a value of green: ");
    scanf("%ld", &green);
    printf("Green in binare: %s\n", print_bin(green));

    printf("Enter a value of blue: ");
    scanf("%ld", &blue);
    printf("Blue in binare: %s\n", print_bin(blue));

    printf("Color in binare: %s\n",
            print_bin(MK_COLOR(red,green,blue)));

    return 0;
}

/* Prints binary value */
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
