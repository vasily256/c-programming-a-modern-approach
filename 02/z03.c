#include <stdio.h>

#define K (4.0f / 3.0f)
#define PI 3.14f

int main(void)
{
    float r;
    
    printf("Enter the radius of sphere: ");
    scanf("%f", &r);
    
    printf("The volume of sphere is: %.2f\n", K * PI * r * r * r);
    
    return 0;
}
