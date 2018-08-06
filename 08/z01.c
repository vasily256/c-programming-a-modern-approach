#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false}, digit_repeat[10] = {false}, repeat_flag = false;
    int digit;
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n);
    
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            digit_repeat[digit] = true;
            repeat_flag = true;
        } else {
            digit_seen[digit] = true;
        }
        n /= 10;
    }
    
    if (repeat_flag) {
        printf("Repeated digit: ");
        for (digit = 0; digit <= 9; digit++) {
            if (digit_repeat[digit]) {
                    printf(" %d", digit);
            }
        }
    } else {
        printf("No repeated digit\n");
    }
    printf("\n");
     
    return 0;
}
