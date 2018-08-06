#include <stdio.h>

int main(void)
{
    float f;
    
    printf("Enter a float value: ");
    scanf("%f", &f);
    printf("Fractional part: %g\n", (float) f - (int) f);
    
    return 0;
}
