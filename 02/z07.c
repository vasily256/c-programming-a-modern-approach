#include <stdio.h>

int main(void)
{
    int amount_total, amount;
    int bill20 = 20, bill10 = 10, bill5 = 5, bill1 = 1;
    int num20, num10, num5, num1;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &amount_total);
    
    num20 = amount_total / bill20;
    amount = num20 * bill20;
    amount_total = amount_total - amount;
    
    num10 = amount_total / bill10;
    amount = num10 * bill10;
    amount_total = amount_total - amount;
    
    num5 = amount_total / bill5;
    amount = num5 * bill5;
    amount_total = amount_total - amount;
    
    num1 = amount_total / bill1;
    amount = num1 * bill1;
    amount_total = amount_total - amount;
    
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", num20, num10, num5, num1);
    
    return 0;
}
