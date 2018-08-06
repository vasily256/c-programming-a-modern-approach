#include <stdio.h>

int main(void)
{
    int n, a1, a0;
    
    printf("Enter a two-digit number: ");
    scanf("%d", &n);
    
    n = n > 0 ? n : -n;
    
    if (n < 10 || n > 99) {
        printf("Error. The number isn't two-digit.\n");
    } else {
        a0 = n % 10;
        a1 = n / 10;
        printf("You entered the number: ");
        switch (a1) {
            case 2:
                printf("twenty");
                break;
            case 3:
                printf("thirty");
                break;
            case 4:
                printf("forty");
                break;
            case 5:
                printf("fifty");
                break;
            case 6:
                printf("sixty");
                break;
            case 7:
                printf("seventy");
                break;
            case 8:
                printf("eighty");
                break;
            case 9:
                printf("ninety");
                break;
            default:
                break;
        }
        if (a1 == 1) {
            switch (a0) {
            case 0:
                printf("ten.\n");
                break;
            case 1:
                printf("eleven.\n");
                break;
            case 2:
                printf("twelve.\n");
                break;
            case 3:
                printf("thirteen.\n");
                break;
            case 4:
                printf("fourteen.\n");
                break;
            case 5:
                printf("fifteen.\n");
                break;
            case 6:
                printf("sixteen.\n");
                break;
            case 7:
                printf("seventeen.\n");
                break;
            case 8:
                printf("eighteen.\n");
                break;
            case 9:
                printf("nineteen.\n");
                break;
            }
        } else {
            switch (a0) {
            case 0:
                printf(".\n");
                break;
            case 1:
                printf("-one.\n");
                break;
            case 2:
                printf("-two.\n");
                break;
            case 3:
                printf("-three.\n");
                break;
            case 4:
                printf("-four.\n");
                break;
            case 5:
                printf("-five.\n");
                break;
            case 6:
                printf("-six.\n");
                break;
            case 7:
                printf("-seven.\n");
                break;
            case 8:
                printf("-eight.\n");
                break;
            case 9:
                printf("-nine.\n");
                break;
            }
        }
    }
    
    return 0;
}
