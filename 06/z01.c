#include <stdio.h>

int main(void)
{
    float number, max = 0.0f;
    for (;;) {
        printf("Enter a number: ");
        scanf("%f", &number);
        if (number > max) {
            max = number;
        } else if (number <= 0.0f) {
            break;
        }
    }
    printf("\nThe largest number entered was %g\n", max);
    
    return 0;
}
