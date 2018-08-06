#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 5

int hand[NUM_CARDS] [2];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyse_hand(void);
void selection_sort(int a[], int n);
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
    char ch, rank_ch, suit_ch;
    bool bad_card, dupl_card;
    int card = 0; 

    while (card < NUM_CARDS) { 
        printf("Enter a card: ");

        bad_card = false;

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           hand[card] [0] = 0;  break;
            case '3':           hand[card] [0] = 1;  break;
            case '4':           hand[card] [0] = 2;  break;
            case '5':           hand[card] [0] = 3;  break;
            case '6':           hand[card] [0] = 4;  break;
            case '7':           hand[card] [0] = 5;  break;
            case '8':           hand[card] [0] = 6;  break;
            case '9':           hand[card] [0] = 7;  break;
            case 't': case 'T': hand[card] [0] = 8;  break;
            case 'j': case 'J': hand[card] [0] = 9;  break;
            case 'q': case 'Q': hand[card] [0] = 10; break;
            case 'k': case 'K': hand[card] [0] = 11; break;
            case 'a': case 'A': hand[card] [0] = 12; break;
            default:            bad_card = true;
        }
        
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': hand[card] [1] = 0;  break;
            case 'd': case 'D': hand[card] [1] = 1;  break;
            case 'h': case 'H': hand[card] [1] = 2;  break;
            case 's': case 'S': hand[card] [1] = 3;  break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n') {
            if (ch != ' ') {
                bad_card = true;
            }
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        }

        dupl_card = false;
        for (int i = 0; i < card; i++) {
            if (hand[i] [0] == hand[card] [0]
                    && hand[i] [1] == hand[card] [1]) {
                dupl_card = true;
                break;
            }
        }
        if (dupl_card) {
            printf("Duplicate card; ignored.\n");
            continue;
        }

        card++;
    }
}

void analyse_hand(void)
{
    int card, rank[NUM_CARDS];

    /* Finds flush */

    flush = true; 
    for (card = 0; card < NUM_CARDS; card++) {
        if (hand[card] [1] != hand[0] [1]) {
            flush = false;
            break;
        }
    }

    /* Finds straight */

    for (card = 0; card < NUM_CARDS; card++)
        rank[card] = hand[card] [0];

    selection_sort(rank, NUM_CARDS);
    straight = true;

    for (card = 1; card < NUM_CARDS; card++) { 
        if (rank[card] != rank[card-1] + 1) {
            straight = false;
            break;
        }
    }

    /* Finds four three and pairs */

    four = false;
    three = false;
    pairs = 0;

    int i, count = 1;
    for (card = 1, i = 0; i < NUM_CARDS; card++) { 
        if (rank[card] == rank[i]) {
            count++;
        } else {
            switch (count) {
                case 2:
                    pairs++;
                    break;
                case 3:
                    three = true;
                    break;
                case 4:
                    four = true;
                    break;
                default:
                    break;
            }
            i = card;
            count = 1;
        }
    } 
}

void selection_sort(int a[], int n)
{
    if (n <= 1) return;

    int i, m = 0;
    
    for (i = 0; i < n; i++)
        if (a[i] > a[m])
            m = i;

    int max = a[m];
    a[m] = a[n-1];
    a[n-1] = max;

    selection_sort(a, n - 1);
}

void print_result(void)
{
    if (straight && flush)
        printf("Straight flush\n");
    else if (four)
        printf("Four-of-a-kind\n");
    else if (three && pairs)
        printf("Full house\n");
    else if (flush)
        printf("Flush\n");
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
