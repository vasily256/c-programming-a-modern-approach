#include <stdio.h> 

#define AVG(x,y) (x+y)/2
#define AVG_F(x,y) (((x)+(y))/2)

#define AREA(x,y) (x)*(y)
#define AREA_F(x,y) ((x)*(y))

int main(void)
{
    double x, y;

    printf("Enter x and y values: ");
    scanf("%lf %lf", &x, &y);

    printf("\n(a) AVG(x,y) / AVG(x,y):\n");
    printf("By original definition: %g\n", AVG(x,y) / AVG(x,y));
    printf("By fixed definition: %g\n", AVG_F(x,y) / AVG_F(x,y));

    printf("\n(a) AREA(x,y) / AREA(x,y):\n");
    printf("By original definition: %g\n", AREA(x,y) / AREA(x,y));
    printf("By fixed definition: %g\n", AREA_F(x,y) / AREA_F(x,y));

    return 0;
}
