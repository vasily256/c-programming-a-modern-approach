#include <stdio.h>

int main(void)
{
    int i, j;
    
    i = 5;
    j = ++i * 3 - 2;
    printf("%d %d\n", i, j);           // (a) 6 16
    
    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d\n", i, j);           // (b) 6 -7
    
    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);           // (c) 6 23
    
    i = 7;
    j = 3 + --i * 2;
    printf("%d %d\n", i, j);           // (d) 6 15
    
    return 0;
}
