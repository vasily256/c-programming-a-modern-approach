#include <stdio.h>

int main(void)
{
    int a, b, c, d, max, min;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if (a > b && a > c && a > d)
        max = a;
    else if (b > c && b > d)
        max = b;
    else if (c > d)
        max = c;
    else
        max = d;
    
    if (a < b && a < c && a < d)
        min = a;
    else if (b < c && b < d)
        min = b;
    else if (c < d)
        min = c;
    else
        min = d;
    
    printf("Largest: %d\nSmallest: %d\n", max, min);
    
    return 0;
}
