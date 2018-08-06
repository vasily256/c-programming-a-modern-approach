#include <stdio.h>

int main(void)
{
    int a = 1, b = 5, c = 10, d = 32, e = 24;
        // (a)
    printf("%d ", a * b - c * d + e );
    printf("%d \n", (((a * b) - (c * d)) + e) );
        // (b)
    printf("%d ", a / b % c / d );
    printf("%d \n", (((a / b) % c) / d) );
       // (c)
    printf("%d ", - a - b + c - + d );
    printf("%d \n", ((((- a) - b) + c) - (+ d)) );
       // (d)
    printf("%d ", a * - b / c - d );
    printf("%d \n", (((a * (- b)) / c) - d) );
    
    return 0;
}
