#include <stdio.h>

int main(void)
{
    float amount, rate, payment;
    int num_payments;
    
    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    
    printf("Enter the number of payments: ");
    scanf("%d", &num_payments);
    
    for (int i = 1; i <= num_payments; i++) {
        amount = amount * (1 + rate / 100 / 12) - payment;
        printf("Balance remaining after payment N %d: $%.2f\n", i, amount);
    }
    
    return 0;
}
