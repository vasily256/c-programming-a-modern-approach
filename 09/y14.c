#include <stdio.h>
#include <stdbool.h>

#define N 5

bool has_zero(int n, int a[n]);

int main(void)
{
    int n = N, i;
    int a[n]; 
    
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (has_zero(n, a))
        printf("Zero\n");
    else
        printf("Not zero\n");

    return 0;
}

bool has_zero(int n, int a[n])
{
    int i;

    for (i = 0; i < n; i++) 
        if (a[i] == 0)
            return true;

    return false;
}
