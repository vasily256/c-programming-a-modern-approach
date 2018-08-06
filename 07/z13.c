#include <stdio.h>

int main(void)
{
    char ch;
    int num_char = 0, num_word = 0;
    float average;
    
    printf("Enter a sentence: ");
    
    scanf(" %c", &ch);
    for (;;) {
        if (ch == '\n') {
            num_word++;
            break;
        } else if (ch == ' ') {
            scanf(" ");
            num_word++;
        } else {
            num_char++;
        }
        ch = getchar();
    }
    
    average = (float) num_char / num_word;
    
    printf("Average word length: %d / %d = %.1f\n", num_char, num_word, average);
    
    return 0;
}
