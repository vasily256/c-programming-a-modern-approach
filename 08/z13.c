#include <stdio.h>
#include <ctype.h>

#define N 20

int main(void)
{
    char ch;
    char chs[N];
    int i;
    
    printf("Enter a first and last name: ");
    
    scanf(" ");
    
    ch = getchar();
    ch = toupper(ch);
    
    while (getchar() != ' ') {
    }
    scanf(" ");
    
    for (i = 0; (chs[i] = getchar()) != '\n'; i++) {
        if (chs[i] == ' ') {
            break;
        }
    }
    
    for (int k = 0; k < i; k++) {
        putchar(chs[k]);
    }
    printf(" %c.\n", ch);
    
    return 0;
}
