#include <stdio.h>

int main(void)
{
    int n = 0;
    
    printf("Enter a mesage: \n");
    while (getchar() != '\n') {
        n++;
    }
    
    printf("You entered %d characters\n", n);
    
    return 0;
}
