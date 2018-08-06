#include <stdio.h>

int main(void)
{
    int i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: \n");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("%20d%20d\n", i, i * i); // 999289 max
    }
    
    return 0;
}
