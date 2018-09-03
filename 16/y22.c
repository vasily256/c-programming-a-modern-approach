#include <stdio.h>

int main(void)
{
    enum chess_pieses {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
    int piece_value[6] = {200, 9, 5, 3, 3, 1};

    printf("(a) King: %d, Rook: %d, Pawn: %d\n",
            piece_value[KING], piece_value[ROOK], piece_value[PAWN]);

    int piece_value2[6] = {
        [KING] = 200,
        [QUEEN] = 9,
        [ROOK] = 5,
        [BISHOP] = 3,
        [KNIGHT] = 3,
        [PAWN] = 1
    };

    printf("(b) King: %d, Rook: %d, Pawn: %d\n",
            piece_value2[KING], piece_value2[ROOK], piece_value2[PAWN]);

    return 0;
}
