#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char str[], int n);
void sort(char *word[], int n);

int main(void)
{
    const int max_word_len = 20;
    int max_num_words = 10;

    int word_len, i;
    char str[max_word_len + 1];
    char **word = malloc(max_num_words * sizeof(char *));
    if (word == NULL) {
        printf("malloc: allocation failed\n");
        return 0;
    }

    for (i = 0; ; i++) {
        printf("Enter word: ");
        word_len = read_line(str, max_word_len);
        if (word_len == 0)
            break;
        if (i == max_num_words) {
            char **tmp_ptr = realloc(word, (max_num_words *= 2) *
                                     sizeof(char *));
            if (tmp_ptr == NULL) {
                printf("realloc: reallocation failed\n");
                i++;
                break;
            }
            word = tmp_ptr;
        } 
        word[i] = malloc((word_len + 1) * sizeof(char));
        if (word[i] == NULL) {
            printf("malloc: allocation failed\n");
            i++;
            break;
        }
        strcpy(word[i], str);
    }

    sort(word, i);

    printf("In sorted order: ");
    for (int j = 0; j < i; j++)
        printf("%s ", word[j]);
    printf("\n");

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

void sort(char *word[], int n)
{
    char *tmp_ptr;

    for (; n >= 2; n--)
        for (int i = 0; i < n - 1; i++)
            if (strcmp(word[i], word[i+1]) > 0) {
                tmp_ptr = word[i];
                word[i] = word[i+1];
                word[i+1] = tmp_ptr;
            }
}

