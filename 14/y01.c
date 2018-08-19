#include <stdio.h> 

#define CUBE(x)           ((x) * (x) * (x))         // (a)
#define REMINDER(x)       ((x) % 4)                 // (b)
#define TEST_PRODUCT(x,y) ((x) * (y) < 100 ? 1 : 0) // (c)

int main(void)
{
    int x, y;

    // (a)
    printf("Enter x and y values: ");
    scanf("%d %d", &x, &y);

    // (b)
    printf("%d ^ 3 = %d\n", x, CUBE(x));
    printf("%d %% 4 = %d\n", x, REMINDER(x)); 

    // (c)
    printf("%d * %d", x, y); 
    if(TEST_PRODUCT(x, y))
        printf(" < 100\n");
    else 
        printf(" > 100\n");

    return 0;
}
