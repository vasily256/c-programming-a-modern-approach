#include <stdio.h>

int main(void)
{
    int zone_code, num1, num2;
    
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &zone_code, &num1, &num2);
    
    printf("You entered: %d.%d.%d\n", zone_code, num1, num2);
    
    return 0;
}
