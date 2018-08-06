#include <stdio.h>

int main(void)
{
    int days, starting_day;
    
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Mon, 7=Sun): ");
    scanf("%d", &starting_day);
    
    for (int i = starting_day; i > 1; i--) {
        printf("   ");
    }
    
    for (int i = 1; i <= days; i++, starting_day++) {
        if (starting_day % 7 == 1) {
            printf("\n");
        }
        printf("%3d", i);
    }
    
    printf("\n");
    return 0;
}
