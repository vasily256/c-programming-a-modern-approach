#include <stdio.h>

int main(void)
{
    float value, commission;
    
    printf("Enter value of trade: ");
    scanf("%f", &value);
    
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
    
    printf("Commission: $%.2f\n", commission);
    
    return 0;
}
