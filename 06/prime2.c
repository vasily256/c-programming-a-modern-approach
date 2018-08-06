#include <stdio.h>

int main(void)
{
    int n, a, i;
    _Bool f = 0;
    
    printf("This program prints prime numbers.\n");
    printf("Enter number of entries: ");
    
    scanf("%d", &n);
    n = n > 0 ? n : -n;
    
    printf("Prime numbers: ");
    
    switch (n) {
        case 0:
            return 0;
        case 1:
            printf("1\n");
            return 0;
        case 2:
            printf("1 2\n");
            return 0;
        default:
            printf("1 2 ");
            break;
    }
    
    for (a = 3; n - 2 != 0; a++) {
        f = 1;
        for (i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                f = 0;
                break;
            }
        }
        if (f) {
            printf ("%d ", a);
            n--;
        }
    }
    printf ("\n");
    
    return 0;
}
