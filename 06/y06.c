// 1 2 4 8 16 32 64 128

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 128; i *= 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}
