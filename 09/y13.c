#include <stdio.h>

int evaluate_position(char board[8] [8]);

int main(void)
{
    int i;
    char board[8] [8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                         {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                         {0},
                         {0},
                         {0},
                         {0},
                         {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                         {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

   
    printf("Balance: %d\n", evaluate_position(board));
}

int evaluate_position(char board[8] [8])
{
    int sum = 0, i, j;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            switch(board[i] [j]) {
                case 'Q': sum += 9; break;
                case 'R': sum += 5; break;
                case 'B': case 'N': sum += 3; break;
                case 'P': sum += 1; break;
                case 'q': sum -= 9; break;
                case 'r': sum -= 5; break;
                case 'b': case 'n': sum -= 3; break;
                case 'p': sum -= 1; break;
                default: break; 
            }
        }
    }
    
    return sum;
}
