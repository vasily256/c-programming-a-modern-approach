#include <stdio.h>

int main(void)
{
    short i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: \n");
    scanf("%hd", &n);
    
    for(i = 1; i <= n; i++) {
        printf("%20d%20d\n", i, i * i); // 32766 max
    }
    
    return 0;
}
