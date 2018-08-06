#include <stdio.h>

int main(void)
{
    int i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: \n");
    scanf("%d", &n);
    getchar();
    
    for (i = 1; i <= n; i++) {
        printf("%15d%15d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to countinue...");
            while(getchar() != '\n') {
            }
        }
    }
    
    return 0;
}
