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
} s;

int main(void)
{
    // (a)
    s.shape_kind = RECTANGLE;           // legal
    
    // (b)
    s.center.x = 10;                    // legal

    // (c)
    // s.height = 25;                   // illegal
    s.u.rectangle.height = 25;          // corrected

    // (d)
    s.u.rectangle.width = 8;            // legal

    // (e)
    // s.u.circle = 5;                   // illegal
    s.u.circle.radius = 5;              // corrected

    // (f)
    //s.u.radius = 5;                   // illegal
    s.u.circle.radius = 5;              // corrected

    return 0;
}
