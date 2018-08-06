#include <stdio.h>

int main(void)
{
    char ch;
    int num_char = 0, num_word = 0;
    float average;
    
    printf("Enter a sentence: ");
    ch = getchar();
    for (;;) {
        if (ch != ' ') {
            if (ch == '\n') {
                break;
            }
            num_word++;
            num_char++;
            while ((ch = getchar()) != ' ') {
                if (ch == '\n') {
                    break;
                }
                num_char++;
            }
        }
        if (ch == ' ') {
            while ((ch = getchar()) == ' ') {
            }
        }
    }
    
    average = (float) num_char / num_word;
    
    printf("Average word length: %d / %d = %.1f\n", num_char, num_word, average);
    
    return 0;
}
