#include <stdio.h>

int main(void)
{
    float amount, rate, payment;
    
    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    
    float balance_1, balance_2, balance_3;
    
    balance_1 = amount * (1 + rate / 100 / 12) - payment;
    balance_2 = balance_1 * (1 + rate / 100 / 12) - payment;
    balance_3 = balance_2 * (1 + rate / 100 / 12) - payment;
    
    printf("Balance remaining after first payment: $%.2f\n", balance_1);
    printf("Balance remaining after second payment: $%.2f\n", balance_2);
    printf("Balance remaining after third payment: $%.2f\n", balance_3);
    
    return 0;
}
