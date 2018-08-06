#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int n[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,1,1,1,1,4,4,8,4,10};
    int scr_val = 0;
    char ch;
    
    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        if (ch < 'A' || ch > 'Z') {
            continue;
        }
        scr_val += n[ch - 'A'];
    }
    printf("Scrabble value: %d\n", scr_val);
    
    return 0;
}
