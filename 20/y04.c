#include <stdio.h>

#define SIZE 64
#define MAX_VALUE 255

#define MK_COLOR(red,green,blue) \
(((red) << 16) + ((green) << 8) + (blue))

int value_control(int value);
char *print_bits(int val);

int main(void)
{
    unsigned long color, red, green, blue;

    printf("Enter a value of red (0 - 255): ");
    scanf("%ld", &red);
    red = value_control(red);
    printf("Red in binare: %s\n", print_bits(red));

    printf("Enter a value of green (0 - 255): ");
    scanf("%ld", &green);
    green = value_control(green);
    printf("Green in binare: %s\n", print_bits(green));

    printf("Enter a value of blue (0 - 255): ");
    scanf("%ld", &blue);
    blue = value_control(blue);
    printf("Blue in binare: %s\n", print_bits(blue));

    color = MK_COLOR(red,green,blue);
    printf("Color in binare: %s\n", print_bits(color));

    return 0;
}

int value_control(int value)
{
    if (value > MAX_VALUE)
        return MAX_VALUE;
    return value;
}

/* Prints binary value */
char *print_bits(int val)
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
