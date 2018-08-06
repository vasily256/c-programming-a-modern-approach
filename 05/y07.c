#include <stdio.h>

int main(void)
{
    float i;
    
    printf("i = ");
    scanf("%f", &i);
    printf("abs(i) = %g\n", i >= 0 ? i : -i );
    
    return 0;
}
