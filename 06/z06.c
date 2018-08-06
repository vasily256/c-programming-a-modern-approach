#include <stdio.h>

int main(void)
{
    int n, s;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    for (int i = 2; (s = i * i) <= n; i += 2) {
        printf("%d\n", s);
    }
    return 0;
}
