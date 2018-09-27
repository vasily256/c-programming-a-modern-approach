#include <stdio.h>

#define SIZE 64
#define MAX_VALUE 255

#define MK_COLOR(red,green,blue) \
(((red) << 16) + ((green) << 8) + (blue))
#define GET_RED(color) ((color) >> 16 & 0xFF)
#define GET_GREEN(color) ((color) >> 8 & 0xFF)
#define GET_BLUE(color) ((color) & 0xFF)

unsigned long value_control(unsigned long value);
char *print_bits(unsigned long val);

int main(void)
{
    unsigned long color, red, green, blue;

    printf("Enter a value of red (0 - 255): ");
    scanf("%ld", &red);
    red = value_control(red);
    printf("Red in binare:   %s\n", print_bits(red));

    printf("Enter a value of green (0 - 255): ");
    scanf("%ld", &green);
    green = value_control(green);
    printf("Green in binare: %s\n", print_bits(green));

    printf("Enter a value of blue (0 - 255): ");
    scanf("%ld", &blue);
    blue = value_control(blue);
    printf("Blue in binare:  %s\n", print_bits(blue));

    color = MK_COLOR(red,green,blue);
    printf("Color in binare: %s\n", print_bits(color));
    printf("Red in binare:   %s\n", print_bits(GET_RED(color)));
    printf("Green in binare: %s\n", print_bits(GET_GREEN(color)));
    printf("Blue in binare:  %s\n", print_bits(GET_BLUE(color)));

    return 0;
}

unsigned long value_control(unsigned long value)
{
    if (value > MAX_VALUE)
        return MAX_VALUE;
    return value;
}

/* Prints bits of binary value */
char *print_bits(unsigned long val)
{
    int i, j, k, b[SIZE];
    static char str[SIZE+SIZE/8];

    if (val > 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;

    if (i % 8) {
        for (j = i; i - j < 8 - j % 8; i++) {
            b[i] = 0;
        }
    }

    for (j = i - 1, i = 0, k = 1; j >= 0; ) {
        str[i++] = b[j--] + '0';
        if (!(k++ % 8))
            str[i++] = ' ';
    }
    str[--i] = '\0';

    return str;
}
