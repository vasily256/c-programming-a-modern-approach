#include <stdio.h>

#define N 10

int main(void)
{
    int i, n;
    
    printf("How many numbers do you want to reverse? ");
    scanf("%d", &n);
    
    int a[n], *p;
    
    printf("Enter %d numbers: ", n);
    for (p = a; p < a + n; p++) {
        scanf("%d", p);
    }
    
    printf("In reverse order:");
    for (p = a + n - 1; p >= a; p--) {
        printf(" %d", *p);
    }
    printf("\n");
    
    return 0;
}
