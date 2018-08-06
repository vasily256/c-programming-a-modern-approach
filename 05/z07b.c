#include <stdio.h>

int main(void)
{
    int a, b, c, d, max, min;
    
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
        
    if (max < c)
        max = c;
    else if (min > c)
        min = c;
    
    if (max < d)
        max = d;
    else if (min > d)
        min = d;
    
    printf("Largest: %d\nSmallest: %d\n", max, min);
    
    return 0;
}
