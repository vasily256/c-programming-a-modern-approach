#include <stdio.h> 

#define INT

#if deined(INT)
#define TYPE int 
#define T d 

#elif deined(DOUBLE)
#define TYPE double
#define T lf 
#endif

#define CUBE(x)           ((x) * (x) * (x))         // (a)
#define REMINDER(x)       ((x) % 4)                 // (b)
#define TEST_PRODUCT(x,y) ((x) * (y) < 100 ? 1 : 0) // (c)

int main(void)
{
    TYPE x, y;
    printf("Enter x and y values: ");
    scanf("%T %T", &x, &y);

    return 0;
}
