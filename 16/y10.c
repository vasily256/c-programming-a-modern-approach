#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

int area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int x, int y);
bool is_inner(struct rectangle r, struct point p);

int main(void)
{
    struct rectangle r; 
    printf("Enter coordinates of rectangle (x1,y1 x2,y2): ");
    scanf("%d,%d %d,%d", &r.upper_left.x, &r.upper_left.y,
            &r.lower_right.x, &r.lower_right.y); 

    struct point p;
    printf("Enter coordinates of point (x,y): ");
    scanf("%d,%d", &p.x, &p.y);

    int x, y;
    printf("Enter offset values (x y): ");
    scanf("%d %d", &x, &y);

    printf("Area: %d\n", area(r));

    printf("Point is%s in rectangle\n", is_inner(r, p) ? "" : " not");

    r = move(r, x, y);
    printf("New coordinates: (%d, %d), (%d, %d)\n",
            r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y);

    return 0;
}

int area(struct rectangle r)
{
    return (r.upper_left.x - r.lower_right.x) * (r.lower_right.y - r.upper_left.y);
}

struct point center(struct rectangle r)
{
    struct point c;

    c.x = (r.upper_left.x + r.lower_right.x) / 2;
    c.y = (r.upper_left.y + r.lower_right.y) / 2;

    return c;
}

struct rectangle move(struct rectangle r, int x, int y)
{
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;

    return r;
}

bool is_inner(struct rectangle r, struct point p)
{
    if (r.upper_left.x > p.x)
        return false;
    else if (r.upper_left.y < p.y)
        return false;
    else if (r.lower_right.x < p.x)
        return false;
    else if (r.lower_right.y > p.y)
        return false;
    else
        return true;
}

