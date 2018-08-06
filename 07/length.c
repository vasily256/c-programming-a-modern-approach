#include <stdio.h>

int main(void)
{
    int n = 0;
    char ch;
    
    printf("Enter a mesage: \n");
    ch = getchar();
    while (ch != '\n') {
        n++;
        ch = getchar();
    }
    
    printf("You entered %d characters\n", n);
    
    return 0;
}
