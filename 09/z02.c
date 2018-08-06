#include <stdio.h>

float tax(float value);

int main(void)
{
    float value;
    
    printf("Enter the amount of taxable income ($): ");
    scanf("%f", &value);
    
    printf("Amount of tax: $%.2f\n", tax(value));
    
    return 0;
}

float tax(float value)
{
    float commission;         

    if (value < 750)
        commission = value * .01;
    else if (value < 2250)
        commission = 7.5 + (value - 750) * .02;
    else if (value < 3750)
        commission = 37.5 + (value - 2250) * .03;
    else if (value < 5250)
        commission = 82.5 + (value - 3750) * .04;
    else if (value < 7000)
        commission = 142.5 + (value - 5250) * .05;
    else
        commission = 230 + (value - 7000) * .06;
    
    return commission;
}
