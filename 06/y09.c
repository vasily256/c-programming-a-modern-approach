// 10 5 3 2 1 1 1 1 1 1 ...

#include <stdio.h>

int main(void)
{
    int i = 10;
    while (i >= 1) {
        printf("%d ", i++);
        i /= 2;
    }
    
    printf("\n");
    
    return 0;
}
