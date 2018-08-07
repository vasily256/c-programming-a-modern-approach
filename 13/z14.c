#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_LEN 30
#define ALPH_LEN 26

bool are_anagrams(const char *word1, const char *word2);
char read_line_a(char str[], int n);

int main(void)
{
    char word1[WORD_LEN + 1] = "", word2[WORD_LEN + 1] = "";
    
    printf("Enter first word: ");
    read_line_a(word1, WORD_LEN);
    
    printf("Enter second word: ");
    read_line_a(word2, WORD_LEN);
    
    if (are_anagrams(word1, word2))
        printf("The words are anagrams\n");
    else
        printf("The words are not anagrams\n");
    
    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{ 
    char alpha_count[ALPH_LEN] = {0};

    while (*word1)
        alpha_count[tolower(*word1++) - 'a']++;

    while (*word2)
        alpha_count[tolower(*word2++) - 'a']--;

    for (int i = 0; i < ALPH_LEN; i++) {
        if (alpha_count[i]) {
            return false;
        }
    }
    return true;
}

char read_line_a(char str[], int n)
{
    char ch, i = 0;

    while (isalpha(ch = getchar()))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}
