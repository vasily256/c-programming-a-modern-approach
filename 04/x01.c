#include <stdio.h>

int main(void)
{
    int i = 5, j = 3;
    printf("%d %d\n", i / j, i % j);      // 1 2
    
    i = 2;
    j = 3;
    printf("%d\n", (i+10) % j);           // 0
    
    i = 7;
    j = 8;
    int k = 9;
    printf("%d\n", (i+10) % k / j);       // 1
    
    return 0;
}
