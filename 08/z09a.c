#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int i, j, r, c, n;
    _Bool k[4] = 0;
    char ch = 'A';
    
    printf("Enter numbers of rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("\n");
    
    char board[r] [c];
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            board[i] [j] = '.';
        }
    }
    
    srand((unsigned) time(NULL));
    
    i = rand() % r;
    j = rand() % c;
    board[i] [j] = ch;
    while (ch <= 'Z') {
        n = rand() % 4;
        if (n == 0 && i > 0 && board[i-1] [j] == '.') {
            i--;
            ch++;
            board[i] [j] = ch;
        } else if (n == 1 && j < c && board[i] [j+1] == '.') {
            j++;
            ch++;
            board[i] [j] = ch;
        } else if (n == 2 && i < r && board[i+1] [j] == '.') {
            i++;
            ch++;
            board[i] [j] = ch;
        } else if (n == 3 && j > 0 && board[i] [j-1] == '.') {
            j--;
            ch++;
            board[i] [j] = ch;
        } else {
            k[n] = 1;
        }
    }
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%c ", board[i] [j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
