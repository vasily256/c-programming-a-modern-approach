#include <stdio.h>

int main(void)
{
    
    int a, c0, c1, c2, c3, c4;
    
    printf("Enter a number between 0 and 32767: ");
    scanf("%5d", &a);
    
    c0 = a % 8;
    c1 = (a = a / 8) % 8;
    c2 = (a = a / 8) % 8;
    c3 = (a = a / 8) % 8;
    c4 = (a = a / 8) % 8;
    
    printf("In octal, you number is: %d%d%d%d%d\n", c4, c3, c2, c1, c0);
    
    return 0;
}
