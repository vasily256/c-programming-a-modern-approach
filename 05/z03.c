#include <stdio.h>

int main(void)
{
    int n; float p, value, commission;
    
    printf("Enter the number of shares: ");
    scanf("%d", &n);
    printf("Enter the price per share: ");
    scanf("%f", &p);
    
    value = n * p;
    
    if (value < 2500)
        commission = 30 + value * .017;
    else if (value < 6250)
        commission = 56 + value * .0066;
    else if (value < 20000)
        commission = 76 + value * .0034;
    else if (value < 50000)
        commission = 100 + value * .0022;
    else if (value < 500000)
        commission = 155 + value * .0011;
    else commission = 255 + value * .0009;
    
    if (commission < 39) commission = 39;
    
    printf("Commission charged by original broker: $%.2f\n", commission);
    
    if (n < 2000)
        commission = 33 + n * .03;
    else commission = 33.2 + n * .02;
    
    printf("Commission charged by a rival broker: $%.2f\n", commission);
    
    return 0;
}
