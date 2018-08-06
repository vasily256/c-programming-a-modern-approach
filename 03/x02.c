#include <stdio.h>

int main(void)
{
    float x = 12.34;
    
    printf("%-8.1e|", x);      // (a)
    printf("%10.6e|", x);      // (b)
    printf("%-8.3f|", x);      // (c)
    printf("%6.0f|", x);       // (c)
    
    return 0;
}
