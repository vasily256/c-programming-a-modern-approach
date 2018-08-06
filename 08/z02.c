#include <stdio.h>

int main(void)
{
    int digit, digit_occur[10] = {0};
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n);
    
    while (n > 0) {
        digit = n % 10;
        digit_occur[digit]++;
        n /= 10;
    }
    
    printf("Digit:        0  1  2  3  4  5  6  7  8  9\nOccurrences:");
    for (digit = 0; digit <= 9; digit++) {
        printf("%3d",digit_occur[digit]);
    }
    printf("\n");

    return 0;
}
