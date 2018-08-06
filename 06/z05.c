#include <stdio.h>

int main(void)
{
    int a, r;
    
    printf("Enter a number: ");
    scanf("%d", &a);
    
    printf("The reversal is: ");
    
    do {
        r = a % 10;
        a /= 10;
        printf("%d", r);
    } while (a != 0);
    
    printf("\n");
    
    return 0;
}
