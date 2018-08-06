#include <stdio.h>

int main(void)
{
    int d, d_max, i, n, a, b, a_max, b_max;
    _Bool f = 0;
    
    printf("This program prints intervals between prime numbers.\n");
    printf("Enter number of entries (0 - terminate): ");
    
    scanf("%d", &n);
    
    printf("Intervals: ");
    
    switch (n) {
        case 0: case 1:
            return 0;
        case 2:
            printf("1\n");
            return 0;
        default:
            printf("1 ");
            break;
    }
    
    b = 2;
    d_max = 1;
    for (a = 3; n - 2 != 0; a++) {
        for (i = 2, f = 1; i < a; i++) {
            if (a % i == 0) {
                f = 0;
                break;
            } else if (a < i * i) {
                f = 1;
                break;
            }
        }
        if (f) {
            printf ("%d ", d = a - b);
            if (d > d_max) {
                d_max = d;
                a_max = a;
                b_max = b;
            }
            b = a;
            n--;
        }
    }   
    printf ("\nMaximal interval %d between %d and %d\n", d_max, b_max, a_max);
    
    return 0;
}
