#include <stdio.h>

int main(void)
{
    int n;
    
    printf("Enter a mesage: \n");
    for (n = 0; getchar() != '\n'; n++) {
    }
    printf("You entered %d characters\n", n);
    
    return 0;
}
