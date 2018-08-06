#include <stdio.h>

int main(void)
{
    long i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: \n");
    scanf("%ld", &n);
    
    for(i = 1; i <= n; i++) {
        printf("%20ld%20ld\n", i, i * i); // too big
    }
    
    return 0;
}
