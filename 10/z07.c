#include <stdio.h>

#define MAX_DIGITS 10
#define DIGIT_WIDTH 4
#define DIGIT_HEIGHT 3

// Digit height 0  _
//              1 |_|
//              2 |_|

//                0123 
//                Digit width

char digits[DIGIT_HEIGHT] [MAX_DIGITS * DIGIT_WIDTH]; 
const int segments[10] [7] = {{1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1, 0, 1},
                              {1, 1, 1, 1, 0, 0, 1},
                              {0, 1, 1, 0, 0, 1, 1},
                              {1, 0, 1, 1, 0, 1, 1},
                              {1, 0, 1, 1, 1, 1, 1},
                              {1, 1, 1, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 0, 1, 1}};

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{ 
    char ch;
    int position = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n'
            && position < MAX_DIGITS * DIGIT_WIDTH) {
        if (ch < '0' || ch > '9') {
            continue;
        }
        process_digit(ch - '0', position);
        position += DIGIT_WIDTH;
    }

    print_digits_array();
}

void clear_digits_array(void)
{
    int i, j;
    for (i = 0; i < DIGIT_HEIGHT; i++) {
        for (j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++) {
            digits[i] [j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{ 
    if (segments[digit] [0]) digits[0] [position+1] = '_';
    if (segments[digit] [1]) digits[1] [position+2] = '|';
    if (segments[digit] [2]) digits[2] [position+2] = '|';
    if (segments[digit] [3]) digits[2] [position+1] = '_';
    if (segments[digit] [4]) digits[2] [position+0] = '|';
    if (segments[digit] [5]) digits[1] [position+0] = '|';
    if (segments[digit] [6]) digits[1] [position+1] = '_'; 
}

void print_digits_array(void)
{
    int i, j;
    for (i = 0; i < DIGIT_HEIGHT; i++) {
        for (j = 0; j < MAX_DIGITS * DIGIT_WIDTH; j++) {
            putchar(digits[i] [j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
