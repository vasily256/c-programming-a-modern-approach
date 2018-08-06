#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 20

int compute_vowel_count(const char *sentence);
int read_line(char sentence[], int n);

int main(void)
{
    char sentence[MAX_LEN+1] = "";
    
    printf("Enter a sentence: ");
    read_line(sentence, MAX_LEN); 
    
    printf("You sentence contains %d vowels\n",
            compute_vowel_count(sentence));
    
    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int num_vowels = 0;

    while (*sentence) {
        switch (tolower(*sentence++)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                num_vowels++;
                break;
            default:
                break;
        }
    }

    return num_vowels;
}

int read_line(char sentence[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            sentence[i++] = ch;
    sentence[i] = '\0';

    return i;
}
