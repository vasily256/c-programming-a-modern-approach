#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
bool straight, ace_low, flush, royal, four, three;
int pairs;

void read_cards(void);
void analyse_hand(void);
void print_result(void);

int main(void)
{
    for(;;) {
        read_cards();
        analyse_hand();
        print_result();
    }
}

void read_cards(void)
{
    bool card_exists[NUM_RANKS] [NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (rank = 0; rank < NUM_RANKS; rank++) {
        for (suit = 0; suit < NUM_SUITS; suit++) {
            card_exists[rank] [suit] = false;
        }
        num_in_rank[rank] = 0;
    }
        
    for (suit = 0; suit < NUM_SUITS; suit++) {
        num_in_suit[suit] = 0;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0;  break;
            case '3':           rank = 1;  break;
            case '4':           rank = 2;  break;
            case '5':           rank = 3;  break;
            case '6':           rank = 4;  break;
            case '7':           rank = 5;  break;
            case '8':           rank = 6;  break;
            case '9':           rank = 7;  break;
            case 't': case 'T': rank = 8;  break;
            case 'j': case 'J': rank = 9;  break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }
        
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0;  break;
            case 'd': case 'D': suit = 1;  break;
            case 'h': case 'H': suit = 2;  break;
            case 's': case 'S': suit = 3;  break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n') {
            if (ch != ' ') {
                bad_card = true;
            }
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else if (card_exists[rank] [suit]) {
            printf("Duplicate card; ignored.\n");
        } else {
            card_exists[rank] [suit] = true;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            cards_read++;
        }
    }
}

void analyse_hand(void)
{
    int rank, suit, num_consec = 0;

    straight = false;
    flush = false;
    royal = false;
    four = false;
    three = false;
    pairs = 0;

    /* Finds flush */
    
    for (suit = 0; suit < NUM_SUITS; suit++) {
        if (num_in_suit[suit] == NUM_CARDS) {
            flush = true;
            break;
        }
    }

    /* Finds straight and royal */

    for (rank = 0; num_in_rank[rank] == 0; rank++);
    while (num_in_rank[rank] > 0 && rank < NUM_RANKS) {
        num_consec++;
        rank++;
    }
    switch (num_consec) {
        case NUM_CARDS:
            if (rank == NUM_RANKS) {
                royal = true;
            } else {
                straight = true;
            } 
            return;
        case NUM_CARDS - 1:
            if (num_in_rank[NUM_RANKS-1] && (num_in_rank[0])) {
                ace_low = true;
            }
    } 

    /* Finds four three and pairs */

    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4)
            four = true;
        if (num_in_rank[rank] == 3)
            three = true;
        if (num_in_rank[rank] == 2)
            pairs++;
    }
}

void print_result(void)
{
    if (royal && flush) 
        printf("Royal flush\n");
    else if (straight && flush)
        printf("Straight flush\n");
    else if (four)
        printf("Four-of-a-kind\n");
    else if (three && pairs)
        printf("Full house\n");
    else if (flush)
        printf("Flush\n");
    else if  (ace_low)
        printf("Ace-low straight\n");
    else if (straight)
        printf("Straight\n");
    else if (three)
        printf("Three-of-a-kind\n");
    else if (pairs == 2)
        printf("Two pairs\n");
    else if (pairs == 1)
        printf("Pair\n");
    else printf("High card\n");

    return;
}
