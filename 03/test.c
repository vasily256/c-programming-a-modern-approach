#include <stdio.h>

int main(void)
{
    int price;
    
    printf("Enter unit price: ");
    scanf("%f", &price);
    
    printf("$%7.2f\n", price);
    
    return 0;
}
