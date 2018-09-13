#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char str[], int n);
int compare(const void *p, const void *r);

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

    qsort(word, i, sizeof(char *), compare);

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

int compare(const void *p, const void *r)
{
    return strcmp(*(char **) p, *(char **) r);
}
