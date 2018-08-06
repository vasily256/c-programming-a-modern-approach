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
    const char *suit_name[] = {"clubs","spades","diamonds","hearts"};
    const char *rank_name[] = {"Two","Three","Four","Five","Six",
        "Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
    
    srand((unsigned) time(NULL));
    
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    
    printf("Your hand: \n");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit] [rank]) {
            in_hand[suit] [rank] = true;
            printf("%s of %s \n", rank_name[rank], suit_name[suit]);
            num_cards--;
        }
    }
    printf("\n");
    
    return 0;
}
