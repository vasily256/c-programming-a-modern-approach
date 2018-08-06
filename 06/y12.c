// 20
#include <stdio.h>

int main(void)
{
    int n = 53, d;
    
    for (d = 2; d * d <= n; d++)
        if (n % d == 0)
            break;
    
    return 0;
}
