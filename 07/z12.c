#include <stdio.h>

int main(void)
{
    float f, g;
    char ch;
    
    printf("Enter an expression: ");
    scanf("%f", &f);
    while ((ch = getchar()) != '\n') {
        scanf("%f", &g);
        switch (ch) {
            case '+':
                f += g;
                break;
            case '-':
                f -= g;
                break;
            case '*':
                f *= g;
                break;
            case '/':
                f /= g;
                break;
            default:
                printf("Invalid operator: %c\n", ch);
                return 0;
        }
    }
    printf("Value of expression: %g\n", f);
    
    return 0;
}
