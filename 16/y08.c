#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

int main(void)
{
    // (a)
    const struct color MAGENTA = {255, 0, 255};
    printf("(a) %d %d %d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    // (b)
    const struct color MAGENTA2 = {.red = 255, .blue = 255}; 
    printf("(b) %d %d %d\n", MAGENTA2.red, MAGENTA2.green, MAGENTA2.blue);

    return 0;
}
