#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define RECTANGLE 0
#define CIRCLE 1

struct point {
    int x, y;
};
struct shape {
    int shape_kind;         /* RECTANGLE or CIRCLE */
    struct point center;    /* coordinates of center */
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
};

int area(struct shape s);
struct shape move(struct shape s, int x, int y);
struct shape scale(struct shape s, double c);

int main(void)
{
    struct shape r = {
        .shape_kind = RECTANGLE,
        .center = {0,0},
        .u.rectangle.height = 6,
        .u.rectangle.width = 4
    };
    struct shape c = {
        .shape_kind = CIRCLE,
        .center = {-1,1},
        .u.circle.radius = 5
    };

    printf("Areas: %d and %d\n", area(r), area(c));

    int x = 3, y = -1;
    printf("Initial coordinations: (%d,%d), (%d,%d).\n",
            r.center.x, r.center.y, c.center.x, c.center.y);
    r = move(r, x, y);
    c = move(c, x, y); 
    printf("Offsets: %d,%d. New coordinates: (%d,%d), (%d,%d)\n",
            x, y, r.center.x, r.center.y, c.center.x, c.center.y);

    double factor = 0.5;
    r = scale(r, factor);
    c = scale(c, factor); 
    printf("Scaling factor %g. Areas after scaling: %d and %d\n",
            factor, area(r), area(c));

    return 0;
}

int area(struct shape s)
{
    switch (s.shape_kind) {
        case RECTANGLE:
            return s.u.rectangle.height * s.u.rectangle.width;
        case CIRCLE:
            return PI * s.u.circle.radius * s.u.circle.radius;
        default:
            exit(EXIT_SUCCESS);
    }
}

struct shape move(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;

    return s;
}

struct shape scale(struct shape s, double c)
{ 
    switch (s.shape_kind) {
        case RECTANGLE:
            s.u.rectangle.height *= c;
            s.u.rectangle.width *= c;
            return s;
        case CIRCLE:
            s.u.circle.radius *= c;
            return s;
        default:
            exit(EXIT_SUCCESS);
    }
}
