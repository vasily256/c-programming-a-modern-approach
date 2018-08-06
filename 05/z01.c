#include <stdio.h>

int main(void)
{
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("The number %d has ", number);
    
    number = number >= 0 ? number : -number;
    
    if (number <= 9)
        printf("1");
    else if (number <= 99)
        printf("2");
    else if (number <= 999)
        printf("3");
    else if (number <= 9999)
        printf("4");
    else
        printf("more than 4");
    
    printf(" digits\n");
    
    return 0;
}
