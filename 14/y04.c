#include <stdio.h> 

#define AVG(x,y) (x+y)/2
#define AVG_F(x,y) ((x+y)/2)

#define AREA(x,y) (x)*(y)
#define AREA_F(x,y) ((x)*(y))

int main(void)
{
    double x, y;

    printf("Enter x and y values: ");
    scanf("%lf %lf", &x, &y);

    printf("(a) AVG(x,y) / AVG(x,y):\n")
    printf("By original definition: %d\n", AVG(x,y) / AVG(x,y));
    printf("By fixed definition: %d\n", AVG_F(x,y) / AVG_F(x,y));

    printf("(a) AREA(x,y) / AREA(x,y):\n");
    printf("By original definition: %d\n", AREA(x,y) / AREA(x,y));
    printf("By fixed definition: %d\n", AREA_F(x,y) / AREA_F(x,y));

    return 0;
}
