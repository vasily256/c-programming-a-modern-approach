#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 50

double compute_average_word_length(const char *sentence);
int read_line(char str[], int n);

int main(void)
{
    char sentence[MAX_LEN+1] = "";
    
    printf("Enter a sentence: ");
    read_line(sentence, MAX_LEN); 
    printf("Average word length: %g\n",
            compute_average_word_length(sentence));
    
    return 0;
}

// Average length of the words in the string

double compute_average_word_length(const char *sentence)
{
    int count_word = 0, count_char = 0;

    while (*sentence) {
        // Counts alphabet characters and words
        if (isalpha(*sentence)) {
            while (isalpha(*sentence)) {
                count_char++;
                sentence++;
            }
            count_word++;
        }
        // Skips non-alphabet characters
        while (*sentence && !isalpha(*sentence))
                sentence++; 
    }

    if (count_word)
        return (double) count_char / count_word;
    else
        return 0.0;
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
