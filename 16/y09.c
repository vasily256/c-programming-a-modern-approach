#include <stdio.h>
#include <stdbool.h>

#define READ_COLOR(red,green,blue,n) \
printf("Enter RGB values "#n": "); \
scanf ("%d %d %d", &red, &green, &blue)

#define PRINT_COLOR(color) printf("RGB %d %d %d\n", color.red, color.green, color.blue)

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);

int main(void)
{
    struct color c1, c2, c3;
    int red, green, blue;
    
    READ_COLOR(red, green, blue, 1);
    c1 = make_color(red, green, blue);
    PRINT_COLOR(c1);

    printf("Red value: %d\n", getRed(c1));

    c3 = brighter(c1);
    printf("Brighter ");
    PRINT_COLOR(c3);

    READ_COLOR(red, green, blue, 2);
    c2 = make_color(red, green, blue);
    PRINT_COLOR(c1);

    printf("Colors are%s equal\n", equal_color(c1, c2) ? "" : " not");

    return 0;
}

struct color make_color(int red, int green, int blue)
{
    struct color c;

    c.red = red;
    c.green = green;
    c.blue = blue;

    return c;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color c1, struct color c2)
{
    return c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue ? true : false;
}

struct color brighter(struct color c)
{
    if (!c.red && !c.green && !c.blue) {
        c.red = 3;
        c.green = 3;
        c.blue = 3;
        return c;
    }

    c.red = (c.red > 0 && c.red < 3 ? 3 : c.red) / 0.7;
    c.green = (c.green > 0 && c.green < 3 ? 3 : c.green) / 0.7;
    c.blue = (c.blue > 0 && c.blue < 3 ? 3 : c.blue) / 0.7;

    c.red = c.red > 255 ? 255 : c.red;
    c.green = c.green > 255 ? 255 : c.green;
    c.blue = c.blue > 255 ? 255 : c.blue;

    return c;
}
