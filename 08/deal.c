#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
    bool in_hand[NUM_SUITS] [NUM_RANKS] = {false};
    int suit, rank, num_cards;
    const char suit_code[] = {'c','d','h','q'};
    const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
    
    srand((unsigned) time(NULL));
    
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit] [rank]) {
            in_hand[suit] [rank] = true;
            printf("%c%c ", rank_code[rank], suit_code[suit]);
            num_cards--;
        }
    }
    printf("\n");
    
    return 0;
}
