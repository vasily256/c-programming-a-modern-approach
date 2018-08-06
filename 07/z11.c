#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch1, ch2;
    
    printf("Enter a first and last name: ");
    
    scanf(" ");
    
    ch1 = getchar();
    ch1 = toupper(ch1);
    
    while (getchar() != ' ') {
    }
    scanf(" ");
    
    while ((ch2 = getchar()) != '\n') {
        if (ch2 == ' ') {
            break;
        }
        putchar(ch2);
    }
    
    printf(" %c.\n", ch1);
    
    return 0;
}
