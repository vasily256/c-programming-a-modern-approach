#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;
    
    for (;;) {
        printf("Enter a number (0 - terminate): ");
        scanf("%ld", &n);
        
        if (n == 0) {
            return 0;
        }

        while (n > 0) {
            digit = n % 10;
            if (digit_seen[digit]) {
                break;
            }
            digit_seen[digit] = true;
            n /= 10;
        }
        
        if (n > 0) {
            printf("Repeated digit\n");
        } else {
            printf("No repeated digit\n");
        }

        for (digit = 0; digit <= 9; digit++) {
            digit_seen[digit] = false;
        }
    } 
}
