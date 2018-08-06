#include <stdio.h>

int main(void)
{
    float amount, tax = 1.05f;
    
    printf("Enter the amount: ");
    scanf("%f", &amount);
    
    printf("With tax added: $%.2f\n", amount * tax);
    
    return 0;
}
