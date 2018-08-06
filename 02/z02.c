#include <stdio.h>

#define K (4.0f / 3.0f)
#define PI 3.14f

int main(void)
{
    float r = 10, v;
    
    v = K * PI * r * r * r;
    
    printf("The volume of sphere is: %.2f\n", v);
    
    return 0;
}
