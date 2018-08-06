#include <stdio.h>

int main(void)
{
    int n;
    
    printf("Enter numerical grade: ");
    scanf("%d", &n);
    
    if (n <= 100) {
        printf("Letter grade: ");
        switch (n / 10) {
            case 10: case 9:
                printf("A\n"); break;
            case 8:
                printf("B\n"); break;
            case 7:
                printf("C\n"); break;
            case 6:
                printf("D\n"); break;
            case 5: case 4: case 3: case 2: case 1: case 0:
                printf("F\n"); break;
            default:
                printf("Grade cannot be less than 0.\n");
        }
    } else printf("Grade cannot be more than 100.\n");
    
    return 0;
}
