#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives,
        int *ones);

int main(void)
{ 
    int amount_total, num20, num10, num5, num1;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount_total);

    pay_amount(amount_total, &num20, &num10, &num5, &num1);

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills:"
            "%d\n$1 bills: %d\n", num20, num10, num5, num1);
    
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives,
        int *ones)
{
    const int bill20 = 20, bill10 = 10, bill5 = 5, bill1 = 1;
    
    *twenties = dollars / bill20;
    dollars %= bill20;
    
    *tens = dollars / bill10;
    dollars %= bill10;
    
    *fives = dollars / bill5;
    dollars %= bill5;
    
    *ones = dollars / bill1;
    dollars %= bill1;
}
