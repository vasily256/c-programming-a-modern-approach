#include <stdio.h>

int main(void)
{
    int i, j;
        //(a) 3 2
    i = 1; j = 2;
    i += j;
    printf("%d %d\n", i, j );
        //(b) 0
    i = 1;
    i--;
    printf("%d\n", i);
        //(c) 1 2
    i = 1; j = 2;
    i * j / i;
    printf("%d %d\n", i, j );
        //(d) 1 3
    i = 1; j = 2;
    i % ++j;
    printf("%d %d\n", i, j );
    
    return 0;
}
