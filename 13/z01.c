#include <stdio.h>
#include <string.h>

#define LEN 20
#define LEN_STOP 4

int read_line(char str[], int n);

int main(void)
{
    char current_word[LEN+1] = "";
    char smallest_word[LEN+1] = "";
    char largest_word[LEN+1] = "";
    int length;

    printf("Enter word: ");
    length = read_line(smallest_word, LEN);
    strcpy(largest_word, smallest_word);

    while (length != LEN_STOP) { 
        printf("Enter word: ");
        length = read_line(current_word, LEN);

        if (strcmp(current_word, smallest_word) < 0)
            strcpy(smallest_word, current_word);
        else if (strcmp(current_word, largest_word) > 0)
            strcpy(largest_word, current_word);
    }

    printf("Smallest word: %s\nLargest word: %s\n",
            smallest_word, largest_word);

    return 0;
} 

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
} 
