//See page 141

#include <stdio.h>

int main(void)
{
    int i;
    char ch;
    
    printf("Enter a number: \n");
    scanf("%d", &i);
    scanf("%c", &ch);
    
    printf("Enter a command: \n");
    scanf("%c", &ch);
    
    printf("You entered command: %c\n", ch);
    
    return 0;
}
