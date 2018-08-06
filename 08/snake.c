#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int i, j, r, c, n;
    int k[4] = {0};
    char ch = '.';
    
    printf("Enter numbers of rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("\n");
    
    char board[r] [c];
    
    r = 2 * r - 1;
    c = 2 * c - 1;
    for (i = 0; i <= r; i++) {
        for (j = 0; j <= c; j++) {
            board[i] [j] = ' ';
        }
    }
    
    srand((unsigned) time(NULL));
    
    i = rand() % r;
    j = rand() % c;
    board[i] [j] = ch;
    for (;;) {
        n = rand() % 4;
        switch (n) {
            case 0:
                if (i > 0 && board[i-1] [j] == ' ') {
                    i--;
                    ch++;
                    board[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 1:
                if (j < c && board[i] [j+1] == ' ') {
                    j++;
                    ch++;
                    board[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 2:
                if (i < r && board[i+1] [j] == ' ') {
                    i++;
                    ch++;
                    board[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
            case 3:
                if (j > 0 && board[i] [j-1] == ' ') {
                    j--;
                    ch++;
                    board[i] [j] = ch;
                    for (int m = 0; m < 4; m++) {
                        k[m] = 0;
                    }
                    break;
                } else {
                    k[n] = 1;
                    break;
                }
        }
        if (k[0] + k[1] + k[2] + k[3] == 4) {
            break;
        }
    }
    
    for (i = 0; i <= r; i++) {
        for (j = 0; j <= c; j++) {
            printf("%c ", board[i] [j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
