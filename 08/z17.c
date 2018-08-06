#include <stdio.h>

#define N 80

int main(void)
{
    short n, i, j, k;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%hd", &n);
    
    short m[n] [n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i] [j] = 0;
        }
    }
    
    i = 0;
    j = n / 2;
    k = 1;
    while (k <= n * n) {
        m[i] [j] = k++;
        if (m[(i - 1 + n) % n] [(j + 1 + n) % n] == 0) {
            i = (--i + n) % n;
            j = (++j + n) % n;
        } else {
            i = (++i + n) % n;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5hd", m[i] [j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
