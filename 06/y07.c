// 9384 938 93 9

#include <stdio.h>

int main(void)
{
    for (int i = 9384; i > 0; i /= 10) {
        printf("%d ", i);
    }
    
    printf("\n");
    
    return 0;
}
