#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DICE 6

bool play_game(void);
int roll_dice(void);

int main(void)
{
    int wins = 0, losses = 0;
    char choise;

    for (;;) {
        srand((unsigned) time(NULL));

        if (play_game()) {
            printf("You win!\n");
            wins++;
        } else {
            printf("You lose!\n");
            losses++;
        }

        printf("\nPlay again (y/n)? ");
        choise = tolower(getchar());
        if (choise == 'y') {
            getchar();
        } else {
            printf("\nWins: %d Losses: %d\n", wins, losses);
            return 0;
        }
    }
}

bool play_game(void)
{
    int point, dice;

    point = roll_dice();
    printf("You rolled: %d\n", point);
    switch(point) {
        case 7: case 11:
            return true;
        case 2: case 3: case 12:
            return false;
        default:
			printf("Your point is %d\n", point);
            break;
    }

    for (;;) {
        dice = roll_dice();
        printf("You rolled: %d\n", dice);
        if (dice == point) {
            return true;
        } else if (dice == 7) {
            return false;
        }
    }
}

int roll_dice(void)
{
    return rand() % MAX_DICE + rand() % MAX_DICE + 2;
}


