#include <stdio.h>

#define SENT_LEN 30
#define WORD_LEN 20

int read_words(int words, int letters,
        char sentence[words] [letters], char terminate_string[]);

int main(void)
{
    int num_word = 0;
    char sentence[SENT_LEN] [WORD_LEN + 1];
    char terminate_string[3] = "\n";

    
    printf("Enter a sentence: ");
    num_word = read_words(SENT_LEN, WORD_LEN + 1, sentence,
            terminate_string); 

    printf("Reversal of sentence:");
 
    while (num_word >= 0)
        printf(" %s", sentence[num_word--]); 
    /*
    for (int i = 0; i <= num_word; i++)
        printf(" %s", sentence[i]); 
        */
    printf("%s", terminate_string);

    return 0;
}

int read_words(int words, int letters,
        char sentence[words] [letters], char terminate_string[])
{
    int w, l;
    char ch;

    for (w = 0; w < words; w++) {
        scanf(" ");
        for (l = 0; l < letters - 1; l++) {
            if ((ch = getchar()) != ' ' && ch != '\n'
                    && ch != '.' && ch != '!' && ch != '?')
                sentence[w] [l] = ch;
            else {
                sentence[w] [l] = '\0';
                break;
            }
        }
        if (ch == '\n')
            break;
        else if (ch == '.' || ch == '!' || ch == '?') {
            terminate_string[0] = ch;
            terminate_string[1] = '\n';
            break;
        }
    }

    return w;
}   
